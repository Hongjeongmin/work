
6
PlaceholderPlaceholder*
dtype0*
shape:
8
Placeholder_1Placeholder*
dtype0*
shape:
8
Placeholder_2Placeholder*
dtype0*
shape:
8
Placeholder_3Placeholder*
dtype0*
shape:
A
random_normal/shapeConst*
valueB:*
dtype0
?
random_normal/meanConst*
valueB
 *    *
dtype0
A
random_normal/stddevConst*
valueB
 *  �?*
dtype0

"random_normal/RandomStandardNormalRandomStandardNormalrandom_normal/shape*
T0*
dtype0*
seed2*
seed�
[
random_normal/mulMul"random_normal/RandomStandardNormalrandom_normal/stddev*
T0
D
random_normalAddrandom_normal/mulrandom_normal/mean*
T0
W
weight1
VariableV2*
dtype0*
shared_name *
shape:*
	container 
~
weight1/AssignAssignweight1random_normal*
T0*
use_locking(*
validate_shape(*
_class
loc:@weight1
F
weight1/readIdentityweight1*
T0*
_class
loc:@weight1
C
random_normal_1/shapeConst*
valueB:*
dtype0
A
random_normal_1/meanConst*
valueB
 *    *
dtype0
C
random_normal_1/stddevConst*
valueB
 *  �?*
dtype0
�
$random_normal_1/RandomStandardNormalRandomStandardNormalrandom_normal_1/shape*
T0*
dtype0*
seed2*
seed�
a
random_normal_1/mulMul$random_normal_1/RandomStandardNormalrandom_normal_1/stddev*
T0
J
random_normal_1Addrandom_normal_1/mulrandom_normal_1/mean*
T0
W
weight2
VariableV2*
dtype0*
shared_name *
shape:*
	container 
�
weight2/AssignAssignweight2random_normal_1*
T0*
use_locking(*
validate_shape(*
_class
loc:@weight2
F
weight2/readIdentityweight2*
T0*
_class
loc:@weight2
C
random_normal_2/shapeConst*
valueB:*
dtype0
A
random_normal_2/meanConst*
valueB
 *    *
dtype0
C
random_normal_2/stddevConst*
valueB
 *  �?*
dtype0
�
$random_normal_2/RandomStandardNormalRandomStandardNormalrandom_normal_2/shape*
T0*
dtype0*
seed2*
seed�
a
random_normal_2/mulMul$random_normal_2/RandomStandardNormalrandom_normal_2/stddev*
T0
J
random_normal_2Addrandom_normal_2/mulrandom_normal_2/mean*
T0
W
weight3
VariableV2*
dtype0*
shared_name *
shape:*
	container 
�
weight3/AssignAssignweight3random_normal_2*
T0*
use_locking(*
validate_shape(*
_class
loc:@weight3
F
weight3/readIdentityweight3*
T0*
_class
loc:@weight3
C
random_normal_3/shapeConst*
valueB:*
dtype0
A
random_normal_3/meanConst*
valueB
 *    *
dtype0
C
random_normal_3/stddevConst*
valueB
 *  �?*
dtype0
�
$random_normal_3/RandomStandardNormalRandomStandardNormalrandom_normal_3/shape*
T0*
dtype0*
seed2"*
seed�
a
random_normal_3/mulMul$random_normal_3/RandomStandardNormalrandom_normal_3/stddev*
T0
J
random_normal_3Addrandom_normal_3/mulrandom_normal_3/mean*
T0
T
bias
VariableV2*
dtype0*
shared_name *
shape:*
	container 
w
bias/AssignAssignbiasrandom_normal_3*
T0*
use_locking(*
validate_shape(*
_class
	loc:@bias
=
	bias/readIdentitybias*
T0*
_class
	loc:@bias
.
mulMulPlaceholderweight1/read*
T0
2
mul_1MulPlaceholder_1weight2/read*
T0

addAddmulmul_1*
T0
2
mul_2MulPlaceholder_2weight3/read*
T0
!
add_1Addaddmul_2*
T0
'
add_2Addadd_1	bias/read*
T0
)
subSubadd_2Placeholder_3*
T0

SquareSquaresub*
T0

RankRankSquare*
T0
5
range/startConst*
value	B : *
dtype0
5
range/deltaConst*
value	B :*
dtype0
:
rangeRangerange/startRankrange/delta*

Tidx0
A
MeanMeanSquarerange*
	keep_dims( *
T0*

Tidx0
8
gradients/ShapeConst*
valueB *
dtype0
@
gradients/grad_ys_0Const*
valueB
 *  �?*
dtype0
W
gradients/FillFillgradients/Shapegradients/grad_ys_0*
T0*

index_type0
C
gradients/Mean_grad/ShapeShapeSquare*
T0*
out_type0
�
gradients/Mean_grad/SizeSizegradients/Mean_grad/Shape*
T0*
out_type0*,
_class"
 loc:@gradients/Mean_grad/Shape
v
gradients/Mean_grad/addAddrangegradients/Mean_grad/Size*
T0*,
_class"
 loc:@gradients/Mean_grad/Shape
�
gradients/Mean_grad/modFloorModgradients/Mean_grad/addgradients/Mean_grad/Size*
T0*,
_class"
 loc:@gradients/Mean_grad/Shape
�
gradients/Mean_grad/Shape_1Shapegradients/Mean_grad/mod*
T0*
out_type0*,
_class"
 loc:@gradients/Mean_grad/Shape
w
gradients/Mean_grad/range/startConst*
value	B : *
dtype0*,
_class"
 loc:@gradients/Mean_grad/Shape
w
gradients/Mean_grad/range/deltaConst*
value	B :*
dtype0*,
_class"
 loc:@gradients/Mean_grad/Shape
�
gradients/Mean_grad/rangeRangegradients/Mean_grad/range/startgradients/Mean_grad/Sizegradients/Mean_grad/range/delta*

Tidx0*,
_class"
 loc:@gradients/Mean_grad/Shape
v
gradients/Mean_grad/Fill/valueConst*
value	B :*
dtype0*,
_class"
 loc:@gradients/Mean_grad/Shape
�
gradients/Mean_grad/FillFillgradients/Mean_grad/Shape_1gradients/Mean_grad/Fill/value*
T0*

index_type0*,
_class"
 loc:@gradients/Mean_grad/Shape
�
!gradients/Mean_grad/DynamicStitchDynamicStitchgradients/Mean_grad/rangegradients/Mean_grad/modgradients/Mean_grad/Shapegradients/Mean_grad/Fill*
T0*
N*,
_class"
 loc:@gradients/Mean_grad/Shape
u
gradients/Mean_grad/Maximum/yConst*
value	B :*
dtype0*,
_class"
 loc:@gradients/Mean_grad/Shape
�
gradients/Mean_grad/MaximumMaximum!gradients/Mean_grad/DynamicStitchgradients/Mean_grad/Maximum/y*
T0*,
_class"
 loc:@gradients/Mean_grad/Shape
�
gradients/Mean_grad/floordivFloorDivgradients/Mean_grad/Shapegradients/Mean_grad/Maximum*
T0*,
_class"
 loc:@gradients/Mean_grad/Shape
p
gradients/Mean_grad/ReshapeReshapegradients/Fill!gradients/Mean_grad/DynamicStitch*
T0*
Tshape0
v
gradients/Mean_grad/TileTilegradients/Mean_grad/Reshapegradients/Mean_grad/floordiv*
T0*

Tmultiples0
E
gradients/Mean_grad/Shape_2ShapeSquare*
T0*
out_type0
D
gradients/Mean_grad/Shape_3Const*
valueB *
dtype0
G
gradients/Mean_grad/ConstConst*
valueB: *
dtype0
~
gradients/Mean_grad/ProdProdgradients/Mean_grad/Shape_2gradients/Mean_grad/Const*
	keep_dims( *
T0*

Tidx0
I
gradients/Mean_grad/Const_1Const*
valueB: *
dtype0
�
gradients/Mean_grad/Prod_1Prodgradients/Mean_grad/Shape_3gradients/Mean_grad/Const_1*
	keep_dims( *
T0*

Tidx0
I
gradients/Mean_grad/Maximum_1/yConst*
value	B :*
dtype0
n
gradients/Mean_grad/Maximum_1Maximumgradients/Mean_grad/Prod_1gradients/Mean_grad/Maximum_1/y*
T0
l
gradients/Mean_grad/floordiv_1FloorDivgradients/Mean_grad/Prodgradients/Mean_grad/Maximum_1*
T0
X
gradients/Mean_grad/CastCastgradients/Mean_grad/floordiv_1*

DstT0*

SrcT0
c
gradients/Mean_grad/truedivRealDivgradients/Mean_grad/Tilegradients/Mean_grad/Cast*
T0
f
gradients/Square_grad/ConstConst^gradients/Mean_grad/truediv*
valueB
 *   @*
dtype0
K
gradients/Square_grad/MulMulsubgradients/Square_grad/Const*
T0
c
gradients/Square_grad/Mul_1Mulgradients/Mean_grad/truedivgradients/Square_grad/Mul*
T0
A
gradients/sub_grad/ShapeShapeadd_2*
T0*
out_type0
K
gradients/sub_grad/Shape_1ShapePlaceholder_3*
T0*
out_type0
�
(gradients/sub_grad/BroadcastGradientArgsBroadcastGradientArgsgradients/sub_grad/Shapegradients/sub_grad/Shape_1*
T0
�
gradients/sub_grad/SumSumgradients/Square_grad/Mul_1(gradients/sub_grad/BroadcastGradientArgs*
	keep_dims( *
T0*

Tidx0
n
gradients/sub_grad/ReshapeReshapegradients/sub_grad/Sumgradients/sub_grad/Shape*
T0*
Tshape0
�
gradients/sub_grad/Sum_1Sumgradients/Square_grad/Mul_1*gradients/sub_grad/BroadcastGradientArgs:1*
	keep_dims( *
T0*

Tidx0
@
gradients/sub_grad/NegNeggradients/sub_grad/Sum_1*
T0
r
gradients/sub_grad/Reshape_1Reshapegradients/sub_grad/Neggradients/sub_grad/Shape_1*
T0*
Tshape0
g
#gradients/sub_grad/tuple/group_depsNoOp^gradients/sub_grad/Reshape^gradients/sub_grad/Reshape_1
�
+gradients/sub_grad/tuple/control_dependencyIdentitygradients/sub_grad/Reshape$^gradients/sub_grad/tuple/group_deps*
T0*-
_class#
!loc:@gradients/sub_grad/Reshape
�
-gradients/sub_grad/tuple/control_dependency_1Identitygradients/sub_grad/Reshape_1$^gradients/sub_grad/tuple/group_deps*
T0*/
_class%
#!loc:@gradients/sub_grad/Reshape_1
C
gradients/add_2_grad/ShapeShapeadd_1*
T0*
out_type0
J
gradients/add_2_grad/Shape_1Const*
valueB:*
dtype0
�
*gradients/add_2_grad/BroadcastGradientArgsBroadcastGradientArgsgradients/add_2_grad/Shapegradients/add_2_grad/Shape_1*
T0
�
gradients/add_2_grad/SumSum+gradients/sub_grad/tuple/control_dependency*gradients/add_2_grad/BroadcastGradientArgs*
	keep_dims( *
T0*

Tidx0
t
gradients/add_2_grad/ReshapeReshapegradients/add_2_grad/Sumgradients/add_2_grad/Shape*
T0*
Tshape0
�
gradients/add_2_grad/Sum_1Sum+gradients/sub_grad/tuple/control_dependency,gradients/add_2_grad/BroadcastGradientArgs:1*
	keep_dims( *
T0*

Tidx0
z
gradients/add_2_grad/Reshape_1Reshapegradients/add_2_grad/Sum_1gradients/add_2_grad/Shape_1*
T0*
Tshape0
m
%gradients/add_2_grad/tuple/group_depsNoOp^gradients/add_2_grad/Reshape^gradients/add_2_grad/Reshape_1
�
-gradients/add_2_grad/tuple/control_dependencyIdentitygradients/add_2_grad/Reshape&^gradients/add_2_grad/tuple/group_deps*
T0*/
_class%
#!loc:@gradients/add_2_grad/Reshape
�
/gradients/add_2_grad/tuple/control_dependency_1Identitygradients/add_2_grad/Reshape_1&^gradients/add_2_grad/tuple/group_deps*
T0*1
_class'
%#loc:@gradients/add_2_grad/Reshape_1
A
gradients/add_1_grad/ShapeShapeadd*
T0*
out_type0
E
gradients/add_1_grad/Shape_1Shapemul_2*
T0*
out_type0
�
*gradients/add_1_grad/BroadcastGradientArgsBroadcastGradientArgsgradients/add_1_grad/Shapegradients/add_1_grad/Shape_1*
T0
�
gradients/add_1_grad/SumSum-gradients/add_2_grad/tuple/control_dependency*gradients/add_1_grad/BroadcastGradientArgs*
	keep_dims( *
T0*

Tidx0
t
gradients/add_1_grad/ReshapeReshapegradients/add_1_grad/Sumgradients/add_1_grad/Shape*
T0*
Tshape0
�
gradients/add_1_grad/Sum_1Sum-gradients/add_2_grad/tuple/control_dependency,gradients/add_1_grad/BroadcastGradientArgs:1*
	keep_dims( *
T0*

Tidx0
z
gradients/add_1_grad/Reshape_1Reshapegradients/add_1_grad/Sum_1gradients/add_1_grad/Shape_1*
T0*
Tshape0
m
%gradients/add_1_grad/tuple/group_depsNoOp^gradients/add_1_grad/Reshape^gradients/add_1_grad/Reshape_1
�
-gradients/add_1_grad/tuple/control_dependencyIdentitygradients/add_1_grad/Reshape&^gradients/add_1_grad/tuple/group_deps*
T0*/
_class%
#!loc:@gradients/add_1_grad/Reshape
�
/gradients/add_1_grad/tuple/control_dependency_1Identitygradients/add_1_grad/Reshape_1&^gradients/add_1_grad/tuple/group_deps*
T0*1
_class'
%#loc:@gradients/add_1_grad/Reshape_1
?
gradients/add_grad/ShapeShapemul*
T0*
out_type0
C
gradients/add_grad/Shape_1Shapemul_1*
T0*
out_type0
�
(gradients/add_grad/BroadcastGradientArgsBroadcastGradientArgsgradients/add_grad/Shapegradients/add_grad/Shape_1*
T0
�
gradients/add_grad/SumSum-gradients/add_1_grad/tuple/control_dependency(gradients/add_grad/BroadcastGradientArgs*
	keep_dims( *
T0*

Tidx0
n
gradients/add_grad/ReshapeReshapegradients/add_grad/Sumgradients/add_grad/Shape*
T0*
Tshape0
�
gradients/add_grad/Sum_1Sum-gradients/add_1_grad/tuple/control_dependency*gradients/add_grad/BroadcastGradientArgs:1*
	keep_dims( *
T0*

Tidx0
t
gradients/add_grad/Reshape_1Reshapegradients/add_grad/Sum_1gradients/add_grad/Shape_1*
T0*
Tshape0
g
#gradients/add_grad/tuple/group_depsNoOp^gradients/add_grad/Reshape^gradients/add_grad/Reshape_1
�
+gradients/add_grad/tuple/control_dependencyIdentitygradients/add_grad/Reshape$^gradients/add_grad/tuple/group_deps*
T0*-
_class#
!loc:@gradients/add_grad/Reshape
�
-gradients/add_grad/tuple/control_dependency_1Identitygradients/add_grad/Reshape_1$^gradients/add_grad/tuple/group_deps*
T0*/
_class%
#!loc:@gradients/add_grad/Reshape_1
K
gradients/mul_2_grad/ShapeShapePlaceholder_2*
T0*
out_type0
J
gradients/mul_2_grad/Shape_1Const*
valueB:*
dtype0
�
*gradients/mul_2_grad/BroadcastGradientArgsBroadcastGradientArgsgradients/mul_2_grad/Shapegradients/mul_2_grad/Shape_1*
T0
g
gradients/mul_2_grad/MulMul/gradients/add_1_grad/tuple/control_dependency_1weight3/read*
T0
�
gradients/mul_2_grad/SumSumgradients/mul_2_grad/Mul*gradients/mul_2_grad/BroadcastGradientArgs*
	keep_dims( *
T0*

Tidx0
t
gradients/mul_2_grad/ReshapeReshapegradients/mul_2_grad/Sumgradients/mul_2_grad/Shape*
T0*
Tshape0
j
gradients/mul_2_grad/Mul_1MulPlaceholder_2/gradients/add_1_grad/tuple/control_dependency_1*
T0
�
gradients/mul_2_grad/Sum_1Sumgradients/mul_2_grad/Mul_1,gradients/mul_2_grad/BroadcastGradientArgs:1*
	keep_dims( *
T0*

Tidx0
z
gradients/mul_2_grad/Reshape_1Reshapegradients/mul_2_grad/Sum_1gradients/mul_2_grad/Shape_1*
T0*
Tshape0
m
%gradients/mul_2_grad/tuple/group_depsNoOp^gradients/mul_2_grad/Reshape^gradients/mul_2_grad/Reshape_1
�
-gradients/mul_2_grad/tuple/control_dependencyIdentitygradients/mul_2_grad/Reshape&^gradients/mul_2_grad/tuple/group_deps*
T0*/
_class%
#!loc:@gradients/mul_2_grad/Reshape
�
/gradients/mul_2_grad/tuple/control_dependency_1Identitygradients/mul_2_grad/Reshape_1&^gradients/mul_2_grad/tuple/group_deps*
T0*1
_class'
%#loc:@gradients/mul_2_grad/Reshape_1
G
gradients/mul_grad/ShapeShapePlaceholder*
T0*
out_type0
H
gradients/mul_grad/Shape_1Const*
valueB:*
dtype0
�
(gradients/mul_grad/BroadcastGradientArgsBroadcastGradientArgsgradients/mul_grad/Shapegradients/mul_grad/Shape_1*
T0
a
gradients/mul_grad/MulMul+gradients/add_grad/tuple/control_dependencyweight1/read*
T0
�
gradients/mul_grad/SumSumgradients/mul_grad/Mul(gradients/mul_grad/BroadcastGradientArgs*
	keep_dims( *
T0*

Tidx0
n
gradients/mul_grad/ReshapeReshapegradients/mul_grad/Sumgradients/mul_grad/Shape*
T0*
Tshape0
b
gradients/mul_grad/Mul_1MulPlaceholder+gradients/add_grad/tuple/control_dependency*
T0
�
gradients/mul_grad/Sum_1Sumgradients/mul_grad/Mul_1*gradients/mul_grad/BroadcastGradientArgs:1*
	keep_dims( *
T0*

Tidx0
t
gradients/mul_grad/Reshape_1Reshapegradients/mul_grad/Sum_1gradients/mul_grad/Shape_1*
T0*
Tshape0
g
#gradients/mul_grad/tuple/group_depsNoOp^gradients/mul_grad/Reshape^gradients/mul_grad/Reshape_1
�
+gradients/mul_grad/tuple/control_dependencyIdentitygradients/mul_grad/Reshape$^gradients/mul_grad/tuple/group_deps*
T0*-
_class#
!loc:@gradients/mul_grad/Reshape
�
-gradients/mul_grad/tuple/control_dependency_1Identitygradients/mul_grad/Reshape_1$^gradients/mul_grad/tuple/group_deps*
T0*/
_class%
#!loc:@gradients/mul_grad/Reshape_1
K
gradients/mul_1_grad/ShapeShapePlaceholder_1*
T0*
out_type0
J
gradients/mul_1_grad/Shape_1Const*
valueB:*
dtype0
�
*gradients/mul_1_grad/BroadcastGradientArgsBroadcastGradientArgsgradients/mul_1_grad/Shapegradients/mul_1_grad/Shape_1*
T0
e
gradients/mul_1_grad/MulMul-gradients/add_grad/tuple/control_dependency_1weight2/read*
T0
�
gradients/mul_1_grad/SumSumgradients/mul_1_grad/Mul*gradients/mul_1_grad/BroadcastGradientArgs*
	keep_dims( *
T0*

Tidx0
t
gradients/mul_1_grad/ReshapeReshapegradients/mul_1_grad/Sumgradients/mul_1_grad/Shape*
T0*
Tshape0
h
gradients/mul_1_grad/Mul_1MulPlaceholder_1-gradients/add_grad/tuple/control_dependency_1*
T0
�
gradients/mul_1_grad/Sum_1Sumgradients/mul_1_grad/Mul_1,gradients/mul_1_grad/BroadcastGradientArgs:1*
	keep_dims( *
T0*

Tidx0
z
gradients/mul_1_grad/Reshape_1Reshapegradients/mul_1_grad/Sum_1gradients/mul_1_grad/Shape_1*
T0*
Tshape0
m
%gradients/mul_1_grad/tuple/group_depsNoOp^gradients/mul_1_grad/Reshape^gradients/mul_1_grad/Reshape_1
�
-gradients/mul_1_grad/tuple/control_dependencyIdentitygradients/mul_1_grad/Reshape&^gradients/mul_1_grad/tuple/group_deps*
T0*/
_class%
#!loc:@gradients/mul_1_grad/Reshape
�
/gradients/mul_1_grad/tuple/control_dependency_1Identitygradients/mul_1_grad/Reshape_1&^gradients/mul_1_grad/tuple/group_deps*
T0*1
_class'
%#loc:@gradients/mul_1_grad/Reshape_1
J
GradientDescent/learning_rateConst*
valueB
 *��'7*
dtype0
�
3GradientDescent/update_weight1/ApplyGradientDescentApplyGradientDescentweight1GradientDescent/learning_rate-gradients/mul_grad/tuple/control_dependency_1*
T0*
use_locking( *
_class
loc:@weight1
�
3GradientDescent/update_weight2/ApplyGradientDescentApplyGradientDescentweight2GradientDescent/learning_rate/gradients/mul_1_grad/tuple/control_dependency_1*
T0*
use_locking( *
_class
loc:@weight2
�
3GradientDescent/update_weight3/ApplyGradientDescentApplyGradientDescentweight3GradientDescent/learning_rate/gradients/mul_2_grad/tuple/control_dependency_1*
T0*
use_locking( *
_class
loc:@weight3
�
0GradientDescent/update_bias/ApplyGradientDescentApplyGradientDescentbiasGradientDescent/learning_rate/gradients/add_2_grad/tuple/control_dependency_1*
T0*
use_locking( *
_class
	loc:@bias
�
GradientDescentNoOp1^GradientDescent/update_bias/ApplyGradientDescent4^GradientDescent/update_weight1/ApplyGradientDescent4^GradientDescent/update_weight2/ApplyGradientDescent4^GradientDescent/update_weight3/ApplyGradientDescent
M
initNoOp^bias/Assign^weight1/Assign^weight2/Assign^weight3/Assign
8

save/ConstConst*
valueB Bmodel*
dtype0
d
save/SaveV2/tensor_namesConst*4
value+B)BbiasBweight1Bweight2Bweight3*
dtype0
O
save/SaveV2/shape_and_slicesConst*
valueBB B B B *
dtype0
�
save/SaveV2SaveV2
save/Constsave/SaveV2/tensor_namessave/SaveV2/shape_and_slicesbiasweight1weight2weight3*
dtypes
2
e
save/control_dependencyIdentity
save/Const^save/SaveV2*
T0*
_class
loc:@save/Const
v
save/RestoreV2/tensor_namesConst"/device:CPU:0*4
value+B)BbiasBweight1Bweight2Bweight3*
dtype0
a
save/RestoreV2/shape_and_slicesConst"/device:CPU:0*
valueBB B B B *
dtype0
�
save/RestoreV2	RestoreV2
save/Constsave/RestoreV2/tensor_namessave/RestoreV2/shape_and_slices"/device:CPU:0*
dtypes
2
v
save/AssignAssignbiassave/RestoreV2*
T0*
use_locking(*
validate_shape(*
_class
	loc:@bias
�
save/Assign_1Assignweight1save/RestoreV2:1*
T0*
use_locking(*
validate_shape(*
_class
loc:@weight1
�
save/Assign_2Assignweight2save/RestoreV2:2*
T0*
use_locking(*
validate_shape(*
_class
loc:@weight2
�
save/Assign_3Assignweight3save/RestoreV2:3*
T0*
use_locking(*
validate_shape(*
_class
loc:@weight3
V
save/restore_allNoOp^save/Assign^save/Assign_1^save/Assign_2^save/Assign_3"