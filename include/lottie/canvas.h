// Created by Autokaka (qq1909698494@gmail.com) on 2024/01/04.

#pragma once

#include <memory>

namespace lottie {

class Canvas : public std::enable_shared_from_this<Canvas> {
 public:
  using Ptr = std::shared_ptr<Canvas>;

  explicit Canvas();
};

}  // namespace lottie
