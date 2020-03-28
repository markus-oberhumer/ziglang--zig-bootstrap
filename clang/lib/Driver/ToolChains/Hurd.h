//===--- Hurd.h - Hurd ToolChain Implementations ----------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_Hurd_H
#define LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_Hurd_H

#include "Gnu.h"
#include "clang/Driver/ToolChain.h"

namespace clang {
namespace driver {
namespace toolchains {

class LLVM_LIBRARY_VISIBILITY Hurd : public Generic_ELF {
public:
  Hurd(const Driver &D, const llvm::Triple &Triple,
       const llvm::opt::ArgList &Args);

  bool HasNativeLLVMSupport() const override;

  void
  AddClangSystemIncludeArgs(const llvm::opt::ArgList &DriverArgs,
                            llvm::opt::ArgStringList &CC1Args) const override;

  virtual std::string computeSysRoot() const;

  virtual std::string getDynamicLinker(const llvm::opt::ArgList &Args) const;

  std::vector<std::string> ExtraOpts;

protected:
  Tool *buildAssembler() const override;
  Tool *buildLinker() const override;

  std::string getMultiarchTriple(const Driver &D,
                                 const llvm::Triple &TargetTriple,
                                 StringRef SysRoot) const override;
};

} // end namespace toolchains
} // end namespace driver
} // end namespace clang

#endif // LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_Hurd_H