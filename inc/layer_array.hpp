#ifndef LAYER_ARRAY_NANOKA_H
#define LAYER_ARRAY_NANOKA_H

#include <rubik_cube_base.hpp>

class Layer_Array
{
public:
    // ���ֹ��캯��
    Layer_Array() : data_len(NANOKA_CASE_NUM * NANOKA_CASE_NUM)
    {
        for (nanoka_num_t i = 0; i < NANOKA_CASE_NUM * NANOKA_CASE_NUM; ++i)
            storage.emplace_back(0);
    }
    Layer_Array(nanoka_num_t len) : data_len(len)
    {
        for (nanoka_num_t i = 0; i < len; ++i)
            storage.emplace_back(0);
    }
    Layer_Array(nanoka_num_t len, std::vector<nanoka_storage_t> data) : data_len(len), storage(data) {}
    Layer_Array(nanoka_num_t len, std::vector<nanoka_storage_t> &data) : data_len(len), storage(data) {}
    Layer_Array(nanoka_num_t len, std::vector<nanoka_storage_t> &&data) : data_len(len), storage(data) {}
    // Ĭ�Ϲ������������
    Layer_Array(Layer_Array &) = default;
    Layer_Array(Layer_Array &&) = default;
    Layer_Array &operator=(Layer_Array &) = default;
    Layer_Array &operator=(Layer_Array &&) = default;
    ~Layer_Array() = default;

    // ��ת��ʮ�Ⱥ��� (Ĭ��˳ʱ��, ���� reverse ������ʱ����ת 90 ��)
    nanoka_status_t route_90(bool reverse);

    // ��ȡ��ǰ������ (�������ⲿ�޸�)
    std::vector<nanoka_storage_t> get_storage(void) const;

    // ��ȡ������ת���������
    std::set<std::vector<nanoka_storage_t>> get_all_route_case(void);

    // �޸���������(0,1,2,3 �ֱ��ʾ�޸� <1,2>,<2,3>,<3,4>,<4,1>)
    nanoka_status_t alter(nanoka_num_t pos, nanoka_num_t data1, nanoka_num_t data2);
    nanoka_status_t alter(nanoka_num_t pos, nanoka_num_t data);
    nanoka_status_t alter(nanoka_num_t pos, std::vector<nanoka_num_t> data);
    nanoka_status_t alter(nanoka_num_t pos, std::pair<nanoka_num_t, nanoka_num_t> data);

    // ����ĸ�����
    nanoka_status_t full(nanoka_num_t color);

private:
    nanoka_num_t data_len;
    std::vector<nanoka_storage_t> storage;
};

#endif