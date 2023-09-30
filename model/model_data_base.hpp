#ifndef _MODEL_DATA_BASE_HPP_
#define _MODEL_DATA_BASE_HPP_
#include <unordered_map>
#include <string>

#include "model_data_structures/model.hpp"
#include "model_operations/model_operation_kernels.hpp"
#include "../intents/intent.hpp"

namespace HPS {
 
  class model_data_base {

  public:   
  Model model;
  Model_Operation_Kernels model_operation_kernels;
    
  public :
  std::unordered_map<std::string , int> int_data_base;
  int to_be_send_data;
  
  void apply_captured_intent(intent intent_from_view)
  {
     if(intent_from_view.current_operation == intent::Operation::ADD)
     {
          to_be_send_data++;
     }

    if(intent_from_view.current_operation == intent::Operation::SUB)
     {
          to_be_send_data--;
     }
  }

  };

}


#endif