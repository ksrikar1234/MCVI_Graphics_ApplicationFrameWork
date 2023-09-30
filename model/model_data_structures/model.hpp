#ifndef _MODEL_DATA_STRUCTURES_HPP_
#define _MODEL_DATA_STRUCTURES_HPP_
#include <vector>
#include <string>
#include <unordered_map>
namespace HPS {
  //-------------------------------------------------------------------+
  // Renderable Entity Format // A common format between Model & view
  //-------------------------------------------------------------------+
  // A Single Data Structure to Represent any Renderable Model
  // (used to transfer RenderData from ( model <-> controller <-> view)
  //-------------------------------------------------------------------+
  
  class Renderable_Entity
  {
    uint64_t UIID;
    std::string name; 
    
    enum class ShadeModel    { FLAT, SMOOTH, GOURAUD };
    enum class PrimitiveType { POINTS, LINES, LINE_STRIP, TRIANGLES, TRIANGLE_STRIP, TRIANGLE_FAN, QUADS, QUAD_STRIP }; 
    enum class ColorSchema   { MONO, PER_PRIMITIVE , PER_VERTEX } ;
    
    ShadeModel shade_model;
    PrimitiveType primitive_type;

    float mono_color[4];
    std::vector<float>  vertex_array, normal_array , color_array , index_array;
    std::vector<float>* vertex_array_ptr, normal_array_ptr , color_array_ptr, index_array_ptr;

  };

  //--------------------------------------------------+
  // Renderable Entity Format End
  //--------------------------------------------------+
  


  class Model {
  public:
  
   std::unordered_map<std::string, Renderable_Entity> Renderables_data_base;
   std::vector<float> vertices;
  
  
  };

}

#endif
