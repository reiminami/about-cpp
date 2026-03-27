## about-cpp

*C++17

## トピック

- 複数ファイルの使用 ([main.cpp](/multiple_files/main.cpp) | [sub.cpp](/multiple_files/sub.cpp))
- ヘッダファイルの使用 ([main.cpp](/use_header/main.cpp) | [f.cpp](/use_header/f.cpp) | [f.hpp](/use_header/f.hpp))
- [ライブラリ](/lib.md)
- [命名規則](/naming.md)
- [データ型](/datatypes.md)
- [ベストプラクティス](/best_practice.md)

## 目次

1. [Hello World](#hello-world)
1. [変数と定数](#変数と定数)
1. [条件分岐](#条件分岐)
1. [ループ](#ループ)
1. [配列](#配列)
1. [コンテナ](#コンテナ)
1. [関数](#関数)
1. [構造体/クラス](#構造体クラス)
1. [ポインタ](#ポインタ)
1. [ポインタとクラス](#ポインタとクラス)
1. [スマートポインタ](#スマートポインタ)
1. [静的](#静的)
1. [テンプレート](#テンプレート)
1. [キャスト](#キャスト)
1. [列挙型](#列挙型)
1. [アルゴリズム](#アルゴリズム)

## Hello World

```cpp
#include <iostream>
using namespace std;    // std::cout がcoutだけで書けます。

int main()
{
    cout << "Hello, World!" << endl;
}
```

```sh
$ g++ sample.cpp -o sample
$ ./sample
Hello, World!
```

```cpp
// コマンドライン引数も使用可能
int main(int argc, char* argv[]) {
    for (int i = 0; i < argc; ++i) {
        cout << argv[i] << endl;
    }
}
```

> 以降の「include」「main関数」は省略

[⬆︎目次へ戻る](#目次)

## 変数と定数

```cpp
std::string name = "John";  // 変数
const double PI = 3.14;     // 定数（変更不可能）
constexpr double TAX = 1.1; // 定数（コンパイル時に評価）

// constexpr がエラーになる例
int num = 10;
constexpr int copyNum = num;    // 既知の値でないためエラー
```

[⬆︎目次へ戻る](#目次)

## 条件分岐

```cpp
// if
if (num == 0) {
} else if (num > 0) {
} else {
}

// switch
switch (num) {
    case 1:
    case 2:
        break;
    case 3:
        break;
    default:
        break;
}
```

[⬆︎目次へ戻る](#目次)

## ループ

```cpp
// 範囲for
for (int num: nums) {
}

// while
while (i < 3) {
}

// do-while
do {
} while (i < 3);

// for
for (int i=0; i<3; i++){
}
```

[⬆︎目次へ戻る](#目次)

## 配列

```cpp
// 配列
int nums[3] = {10, 20, 30};                     // 作成
int numCount = sizeof(nums) / sizeof(nums[0]);  // 要素数

// 多次元配列
int arr[3][2] = {{10, 20}, {30, 40}, {50, 60}};
int rows = sizeof(arr) / sizeof(arr[0]);        // 行数
int cols = sizeof(arr[0]) / sizeof(arr[0][0]);  // 列数
int elms = sizeof(arr) / sizeof(arr[0][0]);     // 要素数

// 動的配列 (C++ではvectorが一般的)
int n;
int* arr;
n = 2;
arr = new int[n] {10, 20};
delete[] arr;
n = 3;
arr = new int[n] {10, 20, 30};
delete[] arr;
```

[⬆︎目次へ戻る](#目次)

## コンテナ

```cpp
// インポート
#include <array>
#include <tuple>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

// array
array<int, 3> arr = {10, 20, 30};
cout << arr[0] << endl;

// tuple
tuple<string, int, int> person = {"John", 170, 60};
string name;
int height, weight;
tie(name, height, weight) = (person);

// pair
pair<string, int> person = {"John", 22};
string name = person.first;
int age     = person.second;
tie(name, age) = person;

// vector
vector<int> v = {10, 20, 30};
auto vdata = v.data();
cout << *vdata << endl;

// map, unordered_map
map<string, int> member = {
    {"John", 20},
    {"Paul", 19},
};
cout << member["John"] << endl;

// set, unordered_set
set<string> member = {
    "John", "Paul"
};
```

```cpp
vector<int> v = {10, 20, 30};

// イテレータ (コンテナを共通の方法で操作)
auto iter = v.begin();
cout << *iter << endl;  // 10
++iter;
cout << *iter << endl;  // 20

// for
for (auto iter = v.begin(); iter != v.end(); ++iter) {
    cout << *iter << endl;
}

// 範囲for
for (auto&& elm : v) {
    cout << elm << endl;
}
```

[⬆︎目次へ戻る](#目次)

## 関数

```cpp
// 基本
void hello(string name) {
    cout << "Hello, " << name << endl;
}
hello("John");  // Hello, John

// デフォルト引数
void hello(string name = "WORLD") {
    cout << "Hello, " << name << endl;
}

// オーバーロード (異なる引数を持つ関数)
void twice(int x)    { cout << x * 2 << endl; }
void twice(double x) { cout << x * 2 << endl; }

// 関数に配列を渡す
void OutputArray(const int* arr) {
    for (int i=0; i<3; i++) cout << arr[i] << endl;
}
int arr[3] = {10, 20, 30};
OutputArray(arr);
```

[⬆︎目次へ戻る](#目次)

## 構造体/クラス

```cpp
// 構造体 (アクセス修飾子のデフォルトはpublic)
struct Human {
};

// クラス (アクセス修飾子のデフォルトはpublic)
class Animal {
};

// 詳細説明
class Rectangle {
    int width;
    int height;
public:
    // コンストラクタ
    Rectangle(int w, int h): width(w), height(h) {}
    // constメンバ関数 (データの改変を防ぐ)
    int area() const {
        return height * width;
    }
    // クラス外での関数定義
    void display();
};

void Rectangle::display() {
    cout << "WIDTH: " << width << " HEIGHT: " << height << endl;
}

// インスタンス生成
Rectangle r(10, 20);
cout << r.area() << endl;
r.display();
```

```cpp
// 継承
class Dad {};
class Kid : public Dad {};

// default (暗黙的に定義されるものを、明示的に定義する)
class A {
    A() = default;
};

// delete (暗黙定義を明示的に禁止。コピー禁止などに使用できる)
class B {
    B(const B&) = delete;
};
B b1;
B b2 = b1;  // エラー
```

## ポインタ

```cpp
// ポインタ (値ではなく、値を指すメモリアドレスを保持)
int age = 22;
int* ptrAge = &age;
cout << *ptrAge << endl;

// nullptr (どの変数も参照していないポインタ)
int* ptrX = nullptr;

// ポインタの動作制御
int x = 99;
const int* ptr1 = &x;           // オブジェクトを不変にする
int* const ptr2 = &x;           // アドレスを不変にする
const int* const ptr3 = &x;     // オブジェクトとアドレスを不変にする

// 参照
int hp = 9999;
int& refHp = hp;
cout << refHp << endl;

// 配列で使う
int arr[3] = {10, 20, 30};
int* ptrArr = arr;
cout << *ptrArr       << endl;  // 10
cout << *(ptrArr + 1) << endl;  // 20

// ポインタ渡し (nullチェック必須)
bool twice(int* num) {
    if (num == nullptr) return false;
    *num *= 2;
    return true;
}
int x = 64;
twice(&x);      // x: 128

// 参照渡し
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
int a = 100;
int b = 200;
swap(a, b);

// クラス操作
Rectangle rect(10, 20);
Rectangle* ptrRect = &rect;
cout << (*ptrRect).area() << endl;
```

[⬆︎目次へ戻る](#目次)

## スマートポインタ

```cpp
// unique_ptr (所有者が１人だけのポインタ)
unique_ptr<int> p1 = make_unique<int>(10);
cout << *p1 << endl;

// move (所有権を移動させる)
unique_ptr<int> p2 = std::move(p1);
cout << *p2 << endl;

// shared_ptr (複数のポインタで同じオブジェクトを共有するポインタ)
shared_ptr<int> p3 = make_shared<int>(30);
shared_ptr<int> p4 = p3;
cout << *p3 << " " << *p4 << endl;

// use_count (参照数を確認) [参照が0になると、自動で削除される]
cout << p4.use_count() << endl; // 2
p4.reset();
cout << p4.use_count() << endl; // 0 (削除)

// weak_ptr (shared_ptrを参照するが、所有権は持たないポインタ)
shared_ptr<int> p5 = make_shared<int>(50);
weak_ptr<int> p6 = p5;
if (auto sp = p6.lock()) {
    cout << *sp << endl;    // 50
}
```

[⬆︎目次へ戻る](#目次)

## 静的

```cpp
// static変数
void countUp() {
    static int cnt = 0;
    cnt++;
    cout << cnt << endl;
}

// staticメンバ関数
struct Calc {
    static int add(int a, int b) { return a + b; }
};
cout << Calc::add(2, 3) << endl;

```

[⬆︎目次へ戻る](#目次)

## テンプレート

```cpp
// template (コンパイル時に型ごとのコードを生成)
template <typename T>
T sum(T a, T b) {
    return a + b;
}
cout << sum(2, 3) << endl;
cout << sum(2.5, 3.5) << endl;

// クラスでの使用例
template <typename T>
struct Calc {
    T width;
    T height;
    Calc(T w, T h): width(w), height(h) {}
    T area() { return width * height; }
};
Calc<int>    a(10, 20);
Calc<double> b(10.5, 20.5);
```

[⬆︎目次へ戻る](#目次)

## キャスト

```cpp
// static_cast (型変換を明示的に行い、必要があれば値を変更)
double pi = 3.14;
int x = static_cast<int>(pi);   // 3

// dynamic_cast (実行時型チェックを伴う、安全なダウンキャスト)
struct Dad {
    virtual ~Dad() {}
};
struct Kid : public Dad {
};
Dad* bro1 = new Kid();
Kid* bro2 = dynamic_cast<Kid*>(bro1);

// const_cast (const修飾を変更)
std::string name = "John";
const string& refName = name;
std::string x = const_cast<string&>(refName);
x = "Paul";

// istringstream (文字列 -> 数値)
#include <sstream>
std::string number = "10";
int n;
istringstream ss;
ss = istringstream(number);
ss >> n;    // n=10

// 文字 -> 数値
char c = '4';
int n = c - '0';    // n=4
```

[⬆︎目次へ戻る](#目次)

## 列挙型

```cpp
// enum (各列挙子は整数、指定なしの場合0から割り振り)
enum Suit {
    Hearts,     // 0
    Diamonds,   // 1
    Clubs = 5,  // 5
    Spades,     // 6
};

// 使用例
Suit s = Suit::Hearts;  // 0
cout << Suit::Clubs;    // 5

// 明示的型変換で数値型に代入可能になる
int x = static_cast<int>(Suit::Hearts);

// enum class (他列挙型の列挙子との名前が被っても問題なし)
enum AA {
    X
};
enum BB {
    X
};
```

[⬆︎目次へ戻る](#目次)

## アルゴリズム

```sh
# 確認方法
$ cd algo
$ make
$ ./main
```

- [BFS (幅優先探索)](/algo/bfs.hpp) - 最短経路を探索
- [DFS (深さ優先探索)](/algo/dfs.hpp) - 省メモリで深く探索

[⬆︎目次へ戻る](#目次)
