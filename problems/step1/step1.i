[Mesh]
  [gmg]
    type = GeneratedMeshGenerator  
    dim = 2
    nx = 100
    ny = 10
    xmax = 0.304
    ymax = 0.0257
  []
  coord_type = RZ
  rz_coord_axis = X
[]

[Variables]
    [pressure]
        # adds a Linear Lagrange variable by default
    []
[]


[Kernels]
  [diff]
    type = ADDiffusion # Laplacian Operator using automatic differentiation
    variable = pressure
  []
[]

[BCs]
    [inlet]
        type = DirichletBC
        variable = pressure
        boundary = left
        value = 4000
    []
    [outlet]
        type = DirichletBC
        variable = pressure
        boundary = right
        value = 0
    []
[]

[Problem]
  type = FEProblem
[]

[Executioner]
    type = Steady
    solve_type = NEWTON
    petsc_options_iname = '-pc_type -pc_hypre_type'
    petsc_options_value = 'hypre  boomeramg'           
[]

[Outputs]
  exodus = true
[]


