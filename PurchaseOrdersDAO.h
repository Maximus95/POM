#pragma once

#include "stdafx.h"
#include "PurchaseOrder.h"
#include "DAO.h"
#include <vector>

class PurchaseOrdersDAO : public DAO{
private:
	PurchaseOrder purchaseOrder;
	vector<PurchaseOrder> *purchaseOrders;

public:

	vector<PurchaseOrder>* getAllPurchaseOrders(){
		purchaseOrders = NULL;
		purchaseOrders = new vector<PurchaseOrder>();
		readFile();

		return purchaseOrders;
	}

	void readFile(){
		vector<string> fileContent;
		ifstream file("PurchaseOrders.txt");
		string stringLine;
		while (getline(file, stringLine))
		{
			fileContent = readLine(stringLine);

			purchaseOrder.setPurchaseOrderID(atoi(fileContent.at(0).c_str()));
			purchaseOrder.setDate(fileContent.at(1));
			purchaseOrder.setPurchaseRequisitionID(atoi(fileContent.at(2).c_str()));
			purchaseOrder.setPurchaseManagerID(atoi(fileContent.at(3).c_str()));
			purchaseOrders->push_back(purchaseOrder);
		}
	}

	void writeFile(){
		ofstream ofs;
		ofs.open("PurchaseOrders.txt", std::ofstream::out | std::ofstream::trunc);

		for (unsigned int i = 0; i < purchaseOrders->size(); i++) {
			ofs << purchaseOrders->at(i).getPurchaseOrderID() << delimeter << purchaseOrders->at(i).getDate() << delimeter << purchaseOrders->at(i).getPurchaseRequisitionID() << delimeter << purchaseOrders->at(i).getPurchaseManagerID() << endl;
		}

		ofs.close();
	}

	void open(){}

	void save(vector<PurchaseOrder> *purchaseOrders){
		this->purchaseOrders = purchaseOrders;
		writeFile();
	}

	void close(){}

};