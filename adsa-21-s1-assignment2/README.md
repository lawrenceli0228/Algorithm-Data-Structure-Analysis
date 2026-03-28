# Assignment 2 — AVL 平衡二叉搜索树

## 题目描述

实现支持插入、删除、遍历的 **AVL 树**（自平衡二叉搜索树）。

## 数据结构

- `Node`：节点，包含 `data`、`left`、`right`、`parent` 指针
- `AvlTrees`：AVL 树类，维护 `root` 指针

## 支持操作

| 操作 | 说明 |
|------|------|
| `insert(value)` | 插入值，重复值忽略，插入后再平衡 |
| `deLete(value)` | 删除值，不存在则忽略，删除后再平衡 |
| `printAvl(order)` | 按指定顺序遍历输出 |

## 旋转类型

- **左旋 `leftRotation`**：处理左-左失衡
- **右旋 `rightRotation`**：处理右-右失衡
- **左右旋 `LefRitRotation`**：处理左-右失衡
- **右左旋 `RitLefRotation`**：处理右-左失衡

## 输入格式

单行，空格分隔的操作序列，最后一个为遍历方式：

```
A<num> D<num> ... <PRE|IN|POST>
```

- `A<num>`：插入数字
- `D<num>`：删除数字
- `PRE` / `IN` / `POST`：前序 / 中序 / 后序遍历

## 示例

```
输入: A5 A3 A7 A1 A4 IN
输出: 1 3 4 5 7

输入: A5 A3 A7 D3 PRE
输出: 5 7

输入: A5 D5 IN
输出: EMPTY
```

## 编译与运行

```bash
g++ -o a2 main.cpp
echo "A5 A3 A7 IN" | ./a2
```
