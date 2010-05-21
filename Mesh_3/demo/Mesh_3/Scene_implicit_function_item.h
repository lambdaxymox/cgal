#ifndef SCENE_IMPLICIT_FUNCTION_ITEM_H
#define SCENE_IMPLICIT_FUNCTION_ITEM_H

#include "Scene_item_with_display_list.h"
#include "Scene_interface.h"
#include "Scene_implicit_function_item_config.h"
#include "Implicit_function_interface.h"
#include "Color_ramp.h"

#define SCENE_IMPLICIT_GRID_SIZE 100


class SCENE_IMPLICIT_FUNCTION_ITEM_EXPORT Scene_implicit_function_item 
  : public Scene_item_with_display_list
{
  Q_OBJECT
  
  typedef qglviewer::ManipulatedFrame ManipulatedFrame;
  
public:
  Scene_implicit_function_item(Implicit_function_interface*);
  virtual ~Scene_implicit_function_item();
  
  Implicit_function_interface* function() const { return function_; }

  bool isFinite() const { return true; }
  bool isEmpty() const { return false; }
  Bbox bbox() const;

  Scene_implicit_function_item* clone() const { return NULL; }

  // rendering mode
  virtual bool supportsRenderingMode(RenderingMode m) const;
  virtual bool manipulatable() const { return true; }
  virtual ManipulatedFrame* manipulatedFrame() { return frame_; }
  
  // draw
  virtual void direct_draw() const { draw(); }
  virtual void direct_draw_edges() const { draw_edges(); }
  virtual void draw() const;
  virtual void draw_edges() const { draw(); }
  
  virtual QString toolTip() const;

public slots:
  void compute_function_grid();

private:
  typedef Scene_interface::Point_         Point;
  typedef std::pair <Point,double>        Point_value;
  
  void draw_bbox() const;
  void draw_function_grid(const Color_ramp&, const Color_ramp&) const;
  void draw_grid_vertex(const Point_value&,
                        const Color_ramp&, const Color_ramp&) const;
  
private:
  Implicit_function_interface* function_;
  ManipulatedFrame* frame_;
  
  bool initialized_;
  int grid_size_;
  double max_value_;
  double min_value_;
  Point_value implicit_grid_[SCENE_IMPLICIT_GRID_SIZE][SCENE_IMPLICIT_GRID_SIZE];
  
  Color_ramp blue_color_ramp_;
  Color_ramp red_color_ramp_;
};

#endif // SCENE_IMPLICIT_FUNCTION_ITEM
