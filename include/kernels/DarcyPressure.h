#pragma once

// including the "ADKernel" Kernel here so we can extend it
#include "ADKernel.h"

/**
 * Computes the residual cotribution K / mu * grad_u * grad_phi.
*/

class DarcyPressure : public ADKernel
{
    public:
    static InputParameters validParams();

    DarcyPressure(const InputParameters & parameters);

    protected:
    virtual ADReal computeQpResidual() override;

    const Real & _permeability;
    const Real & _viscosity;
};