#ifndef __manage_header__
#define __manage_header__

#include <iostream>
#include <vector>



class manage{
private:

public:
    void Read_and_store(std::vector<std::vector<std::string>>& Input);
    void Add_new_entry();
    void delete_entry();
    void test_pass();

};

#endif