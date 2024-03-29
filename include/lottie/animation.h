// Created by Autokaka (qq1909698494@gmail.com) on 2024/01/04.

#pragma once

#include <functional>
#include <optional>
#include <string>

#include "./animation_layer.h"
#include "./canvas.h"

namespace lottie {

struct AnimationSegment {
  float begin_frame;
  float end_frame;
};

struct AnimationConfig {
  std::string path;

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

// TODO(Autokaka): Find out total states, using player state for now...
enum class AnimationPlayState {
  kIdle,
  kBuffering,
  kPlaying,
  kPaused,
  kStopped,
};

enum class AnimationEvent {
  kWillDrawFrame,
  kDidDrawFrame,
  kLoopComplete,
  kComplete,
  kSegmentStart,
  kSegmentEnd,
  kConfigReady,     // when initial config is done
  kCanPlayThrough,  // when all parts of the animation have been loaded
  kDataIncomplete,  // when part of the animation can not be loaded
  kWillLoadImages,
  kDidLoadImages,
  kPlayStateChange,
  kWillDestroy,
  kError,
};

class Animation {
 public:
  using Ptr = std::shared_ptr<Animation>;

  [[nodiscard]] const char* GetName() const;
  void SetName(const char* name);

  [[nodiscard]] bool IsLoaded() const;

  [[nodiscard]] float GetFrameRate() const;
  void SetFrameRate(float frame_rate);
  [[nodiscard]] float GetSpeed() const;
  void SetSpeed(float speed);

  float GetCurrentFrame();
  float GetFirstFrame();
  float GetTotalFrames();
  void Seek(float frame);

  [[nodiscard]] int GetCurrentSegment() const;
  [[nodiscard]] std::vector<AnimationSegment> GetSegments() const;
  void PlaySegments(const std::vector<AnimationSegment>& segments);

  // playcount control
  [[nodiscard]] bool IsAutoplay() const;
  void SetAutoplay(bool autoplay);
  [[nodiscard]] int GetPlayCount() const;
  [[nodiscard]] int GetLoopTimes() const;
  void SetLoopTimes(int loop_times);

  [[nodiscard]] AnimationPlayState GetState() const;
  void SetState(const AnimationPlayState& state);

  [[nodiscard]] bool IsHidden() const;
  void SetHidden(bool hidden);

  void IncludeLayers(const std::vector<AnimationLayer::Ptr>& layers);

  std::size_t AddEventListener(const AnimationEvent& event, const std::function<void()>& callback);
  void RemoveEventListener(std::size_t token);

 private:
  std::string name_;
  bool is_loaded_ = false;
};

}  // namespace lottie
