#pragma once
class cashRegister {
private:
	int cashOnHand;
public:
	cashRegister() {
		cashOnHand = 500;
	}

	cashRegister(int cash_) {
		cashOnHand = cash_;
	}
	int getCurrentBalance() {
		return cashOnHand;
	}

	void acceptAmount(int cash) {
		cashOnHand += cash;
	}

	void makeSale(int cost) {
		cashOnHand -= cost;
	}
};

class dispencerType {
private:
	int numberOfItems;
	int TypeCost;
public:
	dispencerType() {
		numberOfItems = 50;
		TypeCost = 50;
	}

	dispencerType(int number, int cost) {
		numberOfItems = number;
		TypeCost = cost;
	}

	int getNoOfItems() {
		return numberOfItems;
	}

	int getCost() {
		return TypeCost;
	}

	void makeSale() {
		numberOfItems -= 1;
	}
};

