#pragma once
template<typename T> 
class Observer {
    public:
    virtual void field_changed(T& source, const string& field_name_) = 0;
};