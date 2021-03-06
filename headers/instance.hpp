#pragma once
#include <string>
#include <array>
#include <iostream>
#include "drug.hpp"
#include <algorithm>
#include "drugInstance.hpp"
using namespace std;

class Instance
{
    string name;

public:
    vector<DrugInstance> instance_drugs
    {
        // DrugInstance{"Hera", 0, 1000, 300, 600},
        //     DrugInstance{"Speed", 0, 1000, 40, 150},
        //     DrugInstance{"Trawka", 0, 1000, 20, 60},
        //     DrugInstance{"Haszysz", 0, 1000, 30, 150}
    };
    Instance(const string& name_) : name{name_} {}
    void set_drugs(DrugInstance& obj)
    {
        bool is_in_list = false;
        for(auto& tmp : instance_drugs){
            if(tmp.get_name() == obj.get_name()){
                is_in_list = true;
                std::swap(tmp,obj);
            }
            continue; 
        }
        if(is_in_list == false){
            instance_drugs.push_back(obj);        
        }
    }

    Drug get_drug(const string& drug_name_)
    {
        for (auto drug : instance_drugs)
        {
            if (drug.get_name() == drug_name_)
                return drug;
        }
        return Drug{"Empty", 0, 0};
    }
    void add_drug(const string& drug_name, int amount)
    {
        for (auto &obj : instance_drugs)
        {
            if (obj.get_name() == drug_name)
                return obj.set_amount(obj.get_amount() + amount);
        }
        throw runtime_error("Niepowiodła się operacja dodania narkotyku.");
    }
    void substruct_drug(const string& drug_name, int amount)
    {
        for (auto &obj : instance_drugs)
        {
            if (obj.get_name() == drug_name)
                return obj.set_amount(obj.get_amount() - amount);
        }
        throw runtime_error("Niepowiodła się operacja odjęcia narkotyku.");
    }

    void list_all_drugs() const
    {
        for (const auto obj : instance_drugs)
            cout << obj << endl;
    }
};