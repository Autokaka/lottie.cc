// Created by Autokaka (qq1909698494@gmail.com) on 2024/01/04.

#pragma once

#include <cstdint>
#include <memory>
#include <vector>

#include "./animation.h"

namespace lottie {

extern const char* const kRenderQualityLow;
extern const char* const kRenderQualityMedium;
extern const char* const kRenderQualityHigh;

class AnimationCenter {
 public:
  using Ptr = std::shared_ptr<AnimationCenter>;

  static Ptr GetDefaultCenter();
  explicit AnimationCenter();

  void Play(const char* name);
  void Pause(const char* name);
  void Stop(const char* name);
  void SetSpeed(float speed, const char* name);

  void SetRenderQuality(std::uint64_t quality);
  void SetRenderQuality(const char* quality);

  void SetSearchPaths(const std::vector<std::string>& paths);
  [[nodiscard]] std::vector<std::string> GetSearchPaths() const;

  Animation::Ptr Load(const AnimationConfig& config);
  void Destroy(const char* name);

 private:
  std::vector<std::string> search_paths_;
};

}  // namespace lottie
