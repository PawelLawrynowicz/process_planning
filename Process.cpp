class Process {
  private:
    int processID, arrivalT, burstT;
    bool done = false;

  public:
    Process() { processID = -1, arrivalT = -1, burstT = -1; }
    Process(int PID, int AT, int BT) {
        processID = PID;
        arrivalT = AT;
        burstT = BT;
    }
    int getProcessID() { return processID; }
    int getArrivalT() { return arrivalT; }
    int getBurstT() { return burstT; }
    void setProcessID(int newPID){};
    void setArrivalT(int newArrivalT){};
    void setBurstT(int newBurstT) { burstT = newBurstT; };
    bool isFinished() { return done; }
    void finish() { done = true; }
    void undo() { done = false; }
};