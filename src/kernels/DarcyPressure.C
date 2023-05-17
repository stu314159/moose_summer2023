#include "DarcyPressure.h"

registerMooseObject("MooseSummer2023App",DarcyPressure);

InputParameters
DarcyPressure::validParams()
{
    InputParameters params = ADKernel::validParams();
    params.addClassDescription("Compute the diffusion term for Darcy pressure ($p$) equation: "
    "$-\\nabla \\cdot \\frac{\\mathbf{K}}{\\mu} \\nabla p = 0$");

    params.addRequiredParam<Real>("permeability","The permeability ($\\mathrm{K}$) of the fluid.");

    params.addParam<Real>(
        "viscosity",
        7.98e-4,
        "The viscosity ($\\mu$) of the fluid in Pa, the default is for 30 degrees C.");
    
    return params;
    
}

DarcyPressure::DarcyPressure(const InputParameters & parameters)
: ADKernel(parameters),
_permeability(getParam<Real>("permeability")),
_viscosity(getParam<Real>("viscosity"))
{

}

ADReal  
DarcyPressure::computeQpResidual()
{
    return (_permeability / _viscosity) * _grad_test[_i][_qp] * _grad_u[_qp];
}