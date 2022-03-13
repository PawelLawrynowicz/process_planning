#include "Process.cpp"
#include <deque>
#include <fstream>
#include <iostream>
#include <queue>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;
/* pobiera input z klawiatury */
auto getInput(vector<Process> &process) -> bool {
    cout << "Ile procesow chcesz wprowadzic? ";
    int numberOfProcesses = 0;
    cin >> numberOfProcesses;
    int PID = 0;
    int AT = 0;
    int BT = 0;
    for (int i = 0; i < numberOfProcesses; i++) {
        cout << "PID dla procesu " << i + 1 << ":\t";
        cin >> PID;
        cout << "AT dla procesu " << i + 1 << ":\t";
        cin >> AT;
        cout << "BT dla procesu " << i + 1 << ":\t";
        cin >> BT;
        Process tempP(PID, AT, BT);
        process.push_back(tempP);
    }
    return true;
}
/* odpala input z pliku */
auto readFile(const string &fileName, vector<Process> &process) -> bool {
    // otwiera plik

    ifstream file(fileName);
    if (file.is_open()) {
        // Liczy linie w pliku
        int numberOfProcesses = 0;
        string tempLine;
        while (getline(file, tempLine)) {
            ++numberOfProcesses;
        }
        // Zeruje kursor
        file.clear();
        file.seekg(0);
        // Wartosci z pliku do vektora process
        int tempNumber = 0;
        int i = 0;
        int PID = 0;
        int AT = 0;
        int BT = 0;
        while (file >> tempNumber) {
            if (i % 3 == 0) {
                {
                    { PID = tempNumber; }
                }
            } else if (i % 3 == 1) {
                {
                    { AT = tempNumber; }
                }
            } else if (i % 3 == 2) {
                BT = tempNumber;
                Process tempP(PID, AT, BT);
                process.push_back(tempP);
            }
            i++;
        }
        file.close();
        return true;
    }
    cout << "Blad wczytywania z pliku";
    return false;
}
/*zapisuje do pliku*/
void writeFile(float waitingTime, const string &algorithmName) {
    ofstream file;
    file.open("output.txt", ios_base::app);
    file << algorithmName << " - średni czas oczekiwania: " << waitingTime
         << endl;
    file.close();
}
/* sprawdza warunek koncowy; czy kazdy proces jest zakonczony */
auto everyProcessFinished(vector<Process> &process) -> bool {
    for (auto & proces : process) {
        if (!proces.isFinished()) {
            {
                { return false; }
            }
        }
    }
    return true;
}
/* sprawdza czy proces x znajduje sie w kolejce procesow y*/
auto isInQueue(Process &process, const deque<Process *>& queue) -> bool {
    for (auto &i : queue) {
        if (i == &process) {
            {
                { return true; }
            }
        }
    }
    return false;
}
/* ustawia wartosc finished wszystkich procesow na false */
void undo(vector<Process> &process) {
    for (auto &proces : process) {
        proces.undo();
    }
}
/* algorytm fcfs */
void fifo(vector<Process> &process) {

    queue<Process *> queue;
    int time = 0;     // czas
    bool open = true; // czy nastepny proces może zacząć być wykonywanym?
    int currentBurst = -1; // aktualny czas wykonywania
    int waitingTime = 0;   // czas oczekiwania

    cout << endl
         << "***"
         << "FCFS"
         << "***" << endl
         << endl;

    while (!everyProcessFinished(process)) {
        /*Sprawdza ile procesow przybywa w danym czasie i dodaje je do kolejki*/
        for (auto &proces : process) {
            if (proces.getArrivalT() == time && !proces.isFinished()) {
                queue.push(&proces);
            }
        }
        /*Jesli kolejka nie jest pusta i pierwszy proces w kolejce skonczyl
         * wykonywanie, wpuszcza nastepny*/
        if (open && !queue.empty()) {
            currentBurst = queue.front()->getBurstT();
            open = false;
        }
        /*Jeśli kolejka pusta wydrukuj '#'*/
        if (queue.empty()) {
            cout << "#";
        } else {
            /*Obliczenie calkowitego czasu oczekiwania wszystkich procesow w
             * danym czasie*/
            waitingTime += queue.size() - 1;

            /*Jeśli kolejka nie jest pusta wydrukuj nazwe procesu, zmniejsz czas
             * wykonywania o 1*/
            if (currentBurst != 0) {
                cout << "P" << queue.front()->getProcessID();
                currentBurst--;
            }
            /*Jeśli czas wykonywania jest rowny 0, ustaw flage procesu na
            zakończony, usuń go z kolejki i otworz innym procesom droge do
            wykonywania*/
            if (currentBurst == 0) {
                queue.front()->finish();
                queue.pop();
                open = true;
            }
        }
        /*Zwieksz czas o 1*/
        time++;
    }

    /*oblicza sredni czas oczekiwania i wypisuje go*/
    float averageWaitingTime =
        static_cast<float>(waitingTime) / static_cast<float>(process.size());
    cout << endl << "sredni czas oczekiwania: " << averageWaitingTime << endl;

    writeFile(averageWaitingTime, "FCFS");
    /*zaznacz flagi wszystkich procesow na niezrobione*/
    undo(process);
}
/* algorytm sjf niewywlaszczeniowy */
void sjf_nonpreamptive(vector<Process> &process) {
    int time = 0;
    bool open = true;
    int currentBurst = -1;
    int waitingTime = 0;
    deque<Process *> queue;

    cout << endl
         << "***"
         << "SJF"
         << "***" << endl
         << endl;

    while (!everyProcessFinished(process)) {
        /*Sprawdza ile procesow przybywa w danym czasie i dodaje je do kolejki*/
        for (auto &proces : process) {
            if (proces.getArrivalT() == time && !proces.isFinished()) {
                queue.push_back(&proces);
            }
        }
        /*Sortuje kolejke rosnaco wzgledem czasu wykonywania*/
        if (open && queue.size() > 1) {
            /*Sortowanie babelkowe*/
            for (int i = 0; i < queue.size() - 1; i++) {
                for (int j = i + 1; j < queue.size(); j++) {
                    if (queue[j]->getBurstT() < queue[i]->getBurstT()) {
                        Process *temp = queue[i];
                        queue[i] = queue[j];
                        queue[j] = temp;
                    }
                }
            }
        }
        /*Jesli kolejka nie jest pusta i pierwszy proces w kolejce skonczyl
         * wykonywanie, wpuszcza nastepny*/
        if (open && !queue.empty()) {
            currentBurst = queue.front()->getBurstT();
            open = false;
        }
        /*Jesli kolejka jest pusta wydrukuj "#"*/
        if (queue.empty()) {
            cout << "#";
        } else {
            /*Obliczenie calkowitego czasu oczekiwania wszystkich procesow w
             * danym czasie*/
            waitingTime += queue.size() - 1;
            /*Jeśli proces sie jeszcze wykonuje to wydukuj jego nazwe procesu i
             * zmniejsz czas wykonywania o 1*/
            if (currentBurst != 0) {
                cout << "P" << queue.front()->getProcessID();
                currentBurst--;
            }
            /*Jeśli czas wykonywania jest 0, ustaw jego atrybut finished na
             * true, usun z kolejki i "otworz" droge na wejscie nastepnemu
             * procesowi*/
            if (currentBurst == 0) {
                queue.front()->finish();
                queue.pop_front();
                open = true;
            }
        }
        /*zwieksz czas o 1*/
        time++;
    }

    /*Oblicz sredni czas oczekiwania i go wypisz*/
    float averageWaitingTime =
        static_cast<float>(waitingTime) / static_cast<float>(process.size());
    cout << endl << "sredni czas oczekiwania: " << averageWaitingTime << endl;

    writeFile(averageWaitingTime, "SJF");

    /*Ustaw atrybut finished wszystkich procesow na false*/
    undo(process);
}
/* algorytm round robin */
void round_robin(vector<Process> &process, int q) {

    int time = 0;           // czas
    int timeQuantum = q;    // kwant czasu
    deque<Process *> queue; // kolejka
    deque<Process *> todo;  // kolejka rzeczy "do zrobienia później"
    bool open = true; // czy nastepny proces może zacząć być wykonywanym?
    int currentBurst = -1; // aktualny czas wykonywania
    int waitingTime = 0;   // czas oczekiwania

    cout << endl
         << "***"
         << "ROUND ROBIN"
         << "***" << endl
         << endl;

    while (!everyProcessFinished(process)) {

        /*Dodaj wszystkie procesy, które przybyły niepóźniej niż aktualny czas,
         * ponadto musza one nie znajdywac sie juz w kolejce i nie byc
         * skonczone*/
        for (auto &proces : process) {
            if (proces.getArrivalT() <= time && !proces.isFinished() &&
                !isInQueue(proces, queue) && !isInQueue(proces, todo)) {
                queue.push_back(&proces);
            }
        }
        /*Dodaj wszystkie procesy "do zrobienia pozniej" na koniec kolejki i
         * usun je z kolejki "do zrobienia pozniej"*/
        for (int i = 0; i < todo.size(); i++) {
            queue.push_back(todo.front());
            todo.pop_front();
        }
        /*Jesli kolejka jest pusta, wydrukuj "#"*/
        if (queue.empty()) {
            cout << "#";
        }

        else {
            /*Oblicz czas oczekiwania wszystkich procesow w danym czasie*/
            waitingTime += queue.size() - 1;

            /*Jesli droga do wykonywania "otwarta", ustaw aktualny czas
             * wykonywania na pierwszy element kolejki i "zamknij" droge do
             * wykonywania innym procesom*/
            if (open) {
                currentBurst = queue.front()->getBurstT();
                open = false;
            }
            /*Jesli kwant czasu != 0, wydrukuj nazwe procesu, zmniejsz kwant
             * czasu oraz czas wykonywania aktualnego procesu i zapamietaj go na
             * obiekcie*/
            if (timeQuantum != 0) {
                cout << "P" << queue.front()->getProcessID();
                timeQuantum--;
                currentBurst--;
                queue.front()->setBurstT(currentBurst);
            }
            /*Jesli proces wykonal sie do konca, ustaw jego flage finished na
             * true, usun go z poczatku kolejki, zresetuj kwant czasu i "otworz"
             * droge do wykonywania innym procesom*/
            if (currentBurst == 0) {
                queue.front()->finish();
                queue.pop_front();
                timeQuantum = q;
                open = true;
            }
            /*Jesli kwant czasu spadl do 0, dodaj proces do kolejki "do
             * zrobienia później", usuń go z początku kolejki, zresetuj kwant
             * czasu i "otworz droge do wykonywania innym procesom*/
            if (timeQuantum == 0) {
                todo.push_back(queue.front());
                queue.pop_front();
                timeQuantum = q;
                open = true;
            }
        }
        /*zwieksz czas o 1*/
        time++;
    }
    /*Wydrukuj średni czas oczekiwania i wypisz go*/
    float averageWaitingTime =
        static_cast<float>(waitingTime) / static_cast<float>(process.size());
    cout << endl << "sredni czas oczekiwania: " << averageWaitingTime << endl;

    writeFile(averageWaitingTime, "Round robin");
}
/* algorytm hrrn*/
void HRRN(vector<Process> &process) {
    int time = 0;     // czas
    bool open = true; // czy nastepny proces może zacząć być wykonywanym?
    int currentBurst = -1;        // aktualny czas wykonywania
    int waitingTime = 0;          // czas oczekiwania
    deque<Process *> queue;       // kolejka procesow
    vector<float> responseRatios; // wektor response ratios

    cout << endl
         << "***"
         << "HRRN"
         << "***" << endl
         << endl;

    while (!everyProcessFinished(process)) {
        /*Sprawdza ile procesow przybywa w danym czasie i dodaje je do kolejki*/
        for (auto &proces : process) {
            if (proces.getArrivalT() == time && !proces.isFinished()) {
                queue.push_back(&proces);
            }
        }
        /*Jeśli droga do wykonywania procesu jest "otwarta" i kolejka ma wiecej
         * niz 1 element, oblicz response ratio wszystkich procesow w kolejce,
         * nastepnie posortuj je malejąco*/
        if (open && queue.size() > 1) {
            responseRatios.clear();

            for (auto &k : queue) {
                float tempRR = ((static_cast<float>(time) -
                                 static_cast<float>(k->getArrivalT())) +
                                static_cast<float>(k->getBurstT())) /
                               static_cast<float>(k->getBurstT());
                responseRatios.push_back(tempRR);
            }

            for (int i = 0; i < queue.size() - 1; i++) {
                for (int j = i + 1; j < queue.size(); j++) {

                    if (responseRatios[j] > responseRatios[i]) {
                        Process *temp = queue[i];
                        queue[i] = queue[j];
                        queue[j] = temp;
                    }
                }
            }
        }
        /*Jeśli droga do wykonywania procesu "otwarta", ustaw aktualny czas
         * wykonywania na pierwszy element z kolejki i "zamknij" droge do
         * wykonywania*/
        if (open && !queue.empty()) {
            currentBurst = queue.front()->getBurstT();
            open = false;
        }
        /*Jeśli kolejka jest pusta, wydrukuj "#"*/
        if (queue.empty()) {
            cout << "#";
        } else {
            /*Oblicz czas oczekiwania wszystkich procesow w danym czasie*/
            waitingTime += queue.size() - 1;

            /*Jeśli proces nie zakonczyl wykonywania wypisz jego nazwe i
             * zmniejsz czas wykonywania o 1*/
            if (currentBurst != 0) {
                cout << "P" << queue.front()->getProcessID();
                currentBurst--;
            }

            /*Jesli proces zakonczyl wykonywanie, ustaw jego flage finished na
             * true, usun go z poczatku kolejki i "otworz" droge do wykonywania
             * innym procesom*/
            if (currentBurst == 0) {
                queue.front()->finish();
                queue.pop_front();
                open = true;
            }
        }
        /*zwieksz czas o 1*/
        time++;
    }
    /*Oblicz sredni czas wykonywania wszystkich procesow i wypisz go*/
    float averageWaitingTime =
        static_cast<float>(waitingTime) / static_cast<float>(process.size());
    cout << endl << "sredni czas oczekiwania: " << averageWaitingTime << endl;

    writeFile(averageWaitingTime, "HRRN");

    /*Ustaw flage finished wszystkich procesow na false*/
    undo(process);
}

/* menu w konsoli */
void menu(vector<Process> &process) {
    char rawInput = 'e';
    cout << "zamknieta (z) czy otwarta (o) pula zadan? ";
    cin >> rawInput;

    int q = 0;
    cout << "Podaj kwant czasu dla Round Robin: ";
    cin >> q;
    if (rawInput == 'o') {
        getInput(process);
    } else if (rawInput == 'z') {
        readFile("input.txt", process);
    } else {
        cout << "niepoprawny symbol puli zadan" << endl;
    }

    remove("output.txt");

    fifo(process);
    sjf_nonpreamptive(process);
    HRRN(process);
    round_robin(process, q);
    process.clear();
}

auto main() -> int {
    vector<Process> process;
    menu(process);
    getchar();
}
