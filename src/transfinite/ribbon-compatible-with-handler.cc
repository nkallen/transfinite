#include "ribbon-compatible-with-handler.hh"

namespace Transfinite {

RibbonCompatibleWithHandler::~RibbonCompatibleWithHandler() {
}

void
RibbonCompatibleWithHandler::update() {
  RibbonCompatible::update();
  if (!handler_initialized_) {
    resetHandler();
    return;
  }
  Vector3D n = rmf_.eval(0.5);
  Vector3D pt = prev_tangent_ - n * (prev_tangent_ * n);
  Vector3D nt = next_tangent_ - n * (next_tangent_ * n);
  central_ = (handler_ - n * (handler_ * n)) * (pt + nt).norm() / 2.0 * multiplier_;
}

Vector3D
RibbonCompatibleWithHandler::crossDerivative(double s) const {
  Vector3D n = rmf_.eval(s);
  Vector3D pt = prev_tangent_ - n * (prev_tangent_ * n);
  Vector3D nt = next_tangent_ - n * (next_tangent_ * n);
  return pt * 2.0 * (s - 1.0) * (s - 0.5)
    + central_ * -4.0 * s * (s - 1.0)
    + nt * 2.0 * s * (s - 0.5);
}

void
RibbonCompatibleWithHandler::resetHandler() {
  Vector3D n = rmf_.eval(0.5);
  Vector3D pt = prev_tangent_ - n * (prev_tangent_ * n);
  Vector3D nt = next_tangent_ - n * (next_tangent_ * n);
  handler_ = (pt + nt).normalize();
  central_ = (handler_ - n * (handler_ * n)) * (pt + nt).norm() / 2.0 * multiplier_;
  WithHandler::resetHandler();
}

} // namespace Transfinite