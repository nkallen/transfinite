#pragma once

#include <string>

#include "surface-generalized-bezier.hh"

using namespace Transfinite;

CurveVector readLOP(std::string filename);
TriMesh readOBJ(const std::string &filename);
SurfaceGeneralizedBezier loadBezier(const std::string &filename);
void writeBezierControlPoints(const SurfaceGeneralizedBezier &surf, const std::string &filename);