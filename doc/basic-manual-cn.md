# 基本用户手册

## 打开、保存场景

在菜单中选择 `File` --> `Open Scene` 来打开一个 `*.aeproj` 格式的场景项目文件。

在菜单中选择 `File` --> `Save Scene` 或 `Save Scene As` 来保存当前场景。

## 场景中的对象

### 类型

在 Ash Engine 中，一个场景（Scene）中可能包括以下对象：

* Camera（相机）
* Light（光源）
* Gridline（网格线）
* Model（模型）
* Mesh（网格）
* Material（材质）
* Texture（纹理）

### 关系

在 Ash Engine 中，场景中的各个对象及它们的联系是以**树状结构**表示的。它们的层次关系是：

1. 场景是根节点，它的孩子可能有相机、光源、网格线、模型。
2. 模型的孩子可能是网格，也可能是其他模型。
3. 网格的孩子是材质，且每个网格不会拥有多个一个材质。
4. 材质的孩子是纹理，每个材质可能包含多种不同类型的纹理，但同种类型的纹理不会有多个。

### 变换规则

Ash Engine 采用如下的方式来支持对模型和网格的基本变换（平移、旋转、缩放）：

对于树中的模型和网格结点，孩子使用相对于其父亲的局部坐标系（孩子的位置、旋转角、缩放比都是相对于其父亲而言的），你在模型或网格的属性栏中看到的位置值、旋转角和缩放比都是相对的（或者说是局部的）。

在获取某个模型或网格的绝对位置（相对于世界坐标系）时，其自身的变换矩阵首先被应用，其次是父亲、祖先的变换矩阵。变换矩阵（`M`）的定义如下：

```
M = T * R * S
```

其中，`T` 表示平移矩阵，`R` 表示旋转矩阵，`S` 表示缩放矩阵。缩放变换首先被应用，其次是旋转，最后是平移。

## 导入、导出模型（Model）

在菜单中选择 `File` --> `Import Model`，或者直接将模型文件拖放到窗口来导入模型。

选中一个网格（Mesh）或模型（Model），在菜单中选择 `File` --> `Export Model` 以导出该模型。

## 光源

### 类型

Ash Engine 支持四种光源，每种光源最多创建 8 个：

| 类型 | 属性 |
|-----|-----|
|环境光|颜色、光强|
|方向光|颜色、光强、方向|
|点光|颜色、光强、位置、衰减|
|聚光|颜色、光强、位置、方向、内外切角、衰减|

### 衰减

点光和聚光拥有衰减属性，从而能更真实地模拟现实中的光源。Ash Engine 使用二次衰减，公式如下：

![](images/attenuation.svg)

`d` 代表了物体距光源的距离。`Kc`, `Kl`, `Kq` 分别是常数项、一次项和二次项，它们的作用是：

* 常数项通常保持为 1.0，保证分母永远不会比 1 小
* 一次项与距离值相乘，线性地减少光强
* 二次项与距离的平方相乘，平方地减少光强

参数选择参考：

|距离|常数项|一次项|二次项|
|----|----|-----|-----|
|7   |1.0 |0.7  |1.8  |
|13  |1.0 |0.35 |0.44 |
|20  |1.0 |0.22 |0.20 |
|32  |1.0 |0.14 |0.07 |
|50  |1.0 |0.09 |0.032|
|65  |1.0 |0.07 |0.017|
|100 |1.0 |0.045|0.0075|
|160 |1.0 |0.027|0.0028|
|200 |1.0 |0.022|0.0019|
|325 |1.0 |0.014|0.0007|
|600 |1.0 |0.007|0.0002|
|3250|1.0 |0.0014|0.000007|

Ash Engine 中，衰减的默认参数是表中距离为 325 时对应的参数。

## 移动

* 使用 `W` 和 `S` 键来前进和后退
* 使用 `A` 和 `D` 键来左移或右移
* 使用 `E` 和 `Q` 键来上升或下降
* 使用 `Shift` 键来加速移动（5 倍速度）
* 按下鼠标左键并移动鼠标来调整视角

## 三维小控件（Gizmo）

三维小控件可以帮助用户沿三维轴移动、旋转或缩放某个对象，本程序支持的三维小控件包括：

* 三维平移小控件：沿轴平移选定的对象
* 三维旋转小控件：绕轴旋转选定的对象
* 三维缩放小控件：沿轴缩放选定的对象

