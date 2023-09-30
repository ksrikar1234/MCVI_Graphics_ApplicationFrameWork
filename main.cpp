/*
Model_Data_Structures   \                      | <--- User Intent <-------\  
Model_Data_base ---------- <--> Controller <--/                           |-----> VIEW
Model_Operation_Kernels /                     \ ---> Rendereble Entity--->/
*/

#include "app_core.hpp"

int main()
{
   HPS::controller app_controller; 
   
   app_controller.model_db.to_be_send_data = 100;
   app_controller.model_db.model.vertices.push_back(4.0);
   app_controller.pass_data_from_model_db_to_view();
   
   while(!app_controller.viewer.requested_exit())
   {   
     app_controller.viewer.present_view(); 
     app_controller.execute_intent();
    
   }
   
}
