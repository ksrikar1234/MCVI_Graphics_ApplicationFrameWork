#ifndef _INTENT_HPP_
#define _INTENT_HPP_

namespace HPS {

    /*
    Intent: The Intent component in MVI represents the user's intention or action within the application. 
    It encapsulates the user interactions captured by the View and serves as a signal to the Model for state updates or other operations. 
    Intents are dispatched from the View to the Model.

    It Has Two Primary goals. To convey the Service request , data from user to Model Data Base via controller
    & Updates the Model accordingly
    */

    class intent {
        
    public:
    
    uint64_t UUID; // Intent Unique ID
    std::string Name; // Intent name

/*-------------------------------------------------------------------------------
      This Data structure encapsulates the data that is captured from user action 
      from gui & sends it to model_data_base via controller.
---------------------------------------------------------------------------------*/
    class intent_data_structure {
    public :
    int x;
    std::string string; 
    };

    std::vector<intent_data_structure> intent_data_packets; 
/*--------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------
      This Operation structures encapsulates the requested service that is captured from 
      user action from gui & sends it to model_data_base via controller.
---------------------------------------------------------------------------------*/

    enum class Operation      {ADD, SUB, MULTIPLY, DIVIDE};
    enum class ModelOperation {TRANSFORM , SCALE , DELETE};

    Operation current_operation;
    void set_operation(Operation inputOperation);
    };

    void intent::set_operation(Operation inputOperation)
    {
        current_operation = inputOperation;
    }

}


#endif