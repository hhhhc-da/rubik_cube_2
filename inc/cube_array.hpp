#ifndef CUBE_ARRAY_NANOKA_H
#define CUBE_ARRAY_NANOKA_H

#include <rubik_cube_base.hpp>

class Cube_Array{
public:
    Cube_Array();
    Cube_Array(int);
    Cube_Array(int, int);
    ~Cube_Array();

    // ħ����ת����
    nanoka_status cube_move(nanoka_move_t move_type, nanoka_move_enum_t move_step);

private:
    // ħ������
    int cube_num;
    // ħ��ƽ����
    int layer_num;
    // ħ�����ݴ洢��
    uint8_t* cube_storage;
};

#endif