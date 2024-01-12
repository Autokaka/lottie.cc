#include <lottie/animation_center.h>

namespace lottie {

AnimationCenter::AnimationCenter() = default;

AnimationCenter::Ptr AnimationCenter::GetDefaultCenter() {
  static AnimationCenter::Ptr center = std::make_shared<AnimationCenter>();
  return center;
}

void AnimationCenter::Play(const char* name) {
  // TODO(Autokaka):
}

void AnimationCenter::Pause(const char* name) {
  // TODO(Autokaka):
}

void AnimationCenter::Stop(const char* name) {
  // TODO(Autokaka):
}

void AnimationCenter::SetSpeed(float speed, const char* name) {
  // TODO(Autokaka):
}

void AnimationCenter::SetRenderQuality(std::uint64_t quality) {
  // TODO(Autokaka):
}

void AnimationCenter::SetRenderQuality(const char* quality) {
  // TODO(Autokaka):
}

void AnimationCenter::SetSearchPaths(const std::vector<std::string>& paths) {
  // TODO(Autokaka):
}

std::vector<std::string> AnimationCenter::GetSearchPaths() const {
  // TODO(Autokaka):
  return {};
}

Animation::Ptr AnimationCenter::Load(const AnimationConfig& config) {
  // TODO(Autokaka):
  return {};
}

void AnimationCenter::Destroy(const char* name) {
  // TODO(Autokaka):
}

}  // namespace lottie
