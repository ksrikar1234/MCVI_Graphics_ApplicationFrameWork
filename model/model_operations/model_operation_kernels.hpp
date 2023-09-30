#ifndef _MODEL_OPERATION_KERNELS_HPP_
#define _MODEL_OPERATION_KERNELS_HPP_
#include "../model_data_structures/model.hpp"

namespace HPS
{
    class Model_Operation_Kernels
    {
       public:

       void model_scaling_operation(Model& input_model , float scale_factor)
       {
         for(uint i = 0; i < input_model.vertices.size(); ++i)
            {
             input_model.vertices[i] *=  scale_factor;
            }
       }  


    };
} // namespace HPS



#endif