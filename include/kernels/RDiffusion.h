#pragma once

#include "ADKernel.h"

class RDiffusion : public ADKernel
{
    public:
    static InputParameters validParams();

    RDiffusion(const InputParameters & parameters);

    protected:
    virtual ADReal computeQpResidual() override;
};