[Mesh]
    [gmg]
        type = GeneratedMeshGenerator
        dim = 1
        nx = 100
        xmin = 1.0
        xmax = 3.5
    []
[]
    

[Problem]
    type = FEProblem
[]

[Variables]
    [temp]
           # by default, a linear Lagrange temperature variable
    []
[]

[Kernels]
    [source]
        type = HeatSource
        variable = temp
        value = 500
    []
    [diff]
        type = RDiffusion
        variable = temp
    []
[]


[BCs]
    [inner]
        type = DirichletBC
        variable = temp
        boundary = left
        value = 600 # degrees C
    []
    [outer]
        type = DirichletBC
        variable = temp
        boundary = right
        value = 25
    []
[]


[Executioner]
    type = Steady
    solve_type = PJFNK
    petsc_options_iname = '-pc_type -pc_hypre_type'
    petsc_options_value = 'hypre  boomeramg'           
[]
  
[Outputs]
    exodus = true
[]
