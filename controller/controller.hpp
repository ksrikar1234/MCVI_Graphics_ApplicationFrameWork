#ifndef _CONTROLLER_HPP_
#define _CONTROLLER_HPP_
#include "../intents/intent.hpp"
#include "../model/model_data_base.hpp"
#include "../view/view.hpp"

namespace HPS {

   class controller {
   
   public:
   //-----------------------------------+
   model_data_base model_db;
   view& viewer = view::createInstance();
   //-----------------------------------+
    
    controller();
   ~controller(); 
     
   void pass_data_from_model_db_to_view();
   void execute_intent();
   private:
   };
   
   controller::controller()  {   }
   controller::~controller() {   }

   void controller::pass_data_from_model_db_to_view()
   {
      this->viewer.reciever_from_controller = &(this->model_db.to_be_send_data);
   }
   
   void controller::execute_intent()
   {
     this->model_db.apply_captured_intent(this->viewer.capture_intent());
   } 
  
}

#endif