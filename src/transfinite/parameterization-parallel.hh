#pragma once

#include "parameterization-bilinear.hh"

namespace Transfinite {

class ParameterizationParallel : public ParameterizationBilinear {
public:
  virtual ~ParameterizationParallel();
  virtual Point2D mapToRibbon(size_t i, const Point2D &uv) const;
  virtual void update();

protected:
  DoubleVector multipliers_;
};

} // namespace Transfinite
