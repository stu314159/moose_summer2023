#include "RDiffusion.h"

registerMooseObject("MooseSummer2023App",RDiffusion);

InputParameters
RDiffusion::validParams()
{
    InputParameters params = ADKernel::validParams();
    
    
    return params;
    
}

RDiffusion::RDiffusion(const InputParameters & parameters)
: ADKernel(parameters)
{

}


ADReal  
RDiffusion::computeQpResidual()
{
    return _grad_test[_i][_qp] * _grad_u[_qp] * _q_point[_qp](0);
}