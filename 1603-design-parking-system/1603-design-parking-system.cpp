class ParkingSystem {
public:
    vector<int> counts;
    
    ParkingSystem(int big, int medium, int small) {
        counts = {big, medium, small};
    }
    
    bool addCar(int carType) {
        if(counts[carType-1] > 0){
            --counts[carType-1];
            return true;
        }
        
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */