class Cell {
    private: 
        bool isActive;
        bool nextState;
    public:
        Cell();
        void setStatus(bool status);
        bool getStatus() const;

        void setNextState(bool status);
        bool getNextState() const;

        void advance();
};
