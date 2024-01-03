// Created by Autokaka (qq1909698494@gmail.com) on 2024/01/04.

#pragma once

#include <optional>
#include <string>

#include "./canvas.h"

namespace lottie {

struct AnimationSegment {
  float begin_frame;
  float end_frame;
};

struct AnimationConfig {
  // <0: No loop, 0: Infinite loop, >0: Loop times
  int loop_times = 1;
  bool auto_play = false;
  std::optional<AnimationSegment> initial_segment;
  std::string name;
  std::string assets_path;

  bool clear_canvas = false;
  Canvas::Ptr canvas = nullptr;
  bool progressive_load = false;
  // https://developer.mozilla.org/en-US/docs/Web/SVG/Attribute/preserveAspectRatio
  std::string preserve_aspect_ratio = "xMidYMid meet";
  std::string image_preserve_aspect_ratio = "xMidYMid slice";
};

class Animation {
 public:
  using Ptr = std::shared_ptr<Animation>;
};

}  // namespace lottie
