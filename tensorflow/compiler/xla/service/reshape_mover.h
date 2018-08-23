/* Copyright 2017 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#ifndef TENSORFLOW_COMPILER_XLA_SERVICE_RESHAPE_MOVER_H_
#define TENSORFLOW_COMPILER_XLA_SERVICE_RESHAPE_MOVER_H_

#include "tensorflow/compiler/xla/service/hlo_pass_interface.h"

namespace xla {

// A pass which moves Reshapes and Transposes to let later passes combine them.
// This now only moves them outputward across elementwise ops all whose operands
// are equivalent Reshapes or Transposes, but in future could potentially move
// them inputward also.
class ReshapeMover : public HloPassInterface {
 public:
  absl::string_view name() const override { return "reshape-mover"; }

  StatusOr<bool> Run(HloModule* module) override;
};

}  // namespace xla

#endif  // TENSORFLOW_COMPILER_XLA_SERVICE_RESHAPE_MOVER_H_
