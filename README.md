## about-cpp

*C++17

## トピック

- [命名規則](/naming.md)
- [データ型](/datatypes.md)

## 目次

1. [Hello World](#hello-world)
1. [変数と定数](#変数と定数)
1. [条件分岐](#条件分岐)
1. [ループ](#ループ)
1. [配列](#配列)
1. [多次元配列](#多次元配列)
1. [動的配列](#動的配列)
1. [関数](#関数)
1. [構造体](#構造体)
1. [クラス](#クラス)
1. [default / delete](#default--delete)
1. [ポインタ](#ポインタ)
1. [ポインタと配列](#ポインタと配列)
1. [ポインタと関数](#ポインタと関数)
1. [ポインタとクラス](#ポインタとクラス)
1. [スマートポインタ](#スマートポインタ)
1. [静的](#静的)
1. [テンプレート](#テンプレート)
1. [キャスト](#キャスト)
1. [列挙型](#列挙型)
1. [コマンドライン引数](#コマンドライン引数)
1. [コンテナ](#コンテナ)
1. [イテレータ](#イテレータ)
1. [iostream (標準入出力)](#iostream-標準入出力)
1. [fstream (ファイル)](#fstream-ファイル)
1. [cmath (数学)](#cmath-数学)
1. [string (文字列)](#string-文字列)
1. [cstring (文字列操作)](#cstring-文字列操作)
1. [ctime (時間)](#ctime-時間)
1. [vector (ベクター)](#vector-ベクター)
1. [algorithm (アルゴリズム)](#algorithm-アルゴリズム)
1. [ビット](#ビット)
1. [複数ファイルの使用](#複数ファイルの使用)
1. [ヘッダファイルの使用](#ヘッダファイルの使用)

## Hello World

- コードを用意します。

```cpp
#include <iostream>
using namespace std;    // std::coutがcout、std::endlがendlと省略可能になります

int main()
{
    cout << "Hello, World!" << endl;
}
```

- ターミナル等でコンパイル＆実行を行います。

```sh
$ g++ sample.cpp -o sample
$ ./sample
Hello, World!
```

> 以降、「インクルード」と「main関数」、「using句」の記載は省略します。

[⬆︎目次へ戻る](#目次)

## 変数と定数

- 変数には様々な方法で値を代入できます。

```cpp
int age;
age = 20;
age = {21};
age = (22);
```

- `const`は変更不可能な定数です。

```cpp
const double PI = 3.14;
```

- `constexpr`はコンパイル時に評価されるため、コンパイル時に既知の値でなければエラーになります。

```cpp
constexpr double TAX = 1.1; // OK

int a = 0;
constexpr int b = a;        // エラー
```

[⬆︎目次へ戻る](#目次)

## 条件分岐

- if文が使えます。

```cpp
if (num == 0) {
    cout << "A";
} else if (num > 0) {
    cout << "B";
} else {
    cout << "C";
}
```

- switch文も使えます。

```cpp
int score = 5;
switch (score) {
    case 1:
    case 2:
        cout << "Low";
        break;
    case 3:
        cout << "Mid";
        break;
    case 4:
    case 5:
        cout << "High";
        break;
    default:
        cout << "Default";
        break;
}
```

[⬆︎目次へ戻る](#目次)

## ループ

- 範囲forが使えます。

```cpp
for (int num: nums) {
    cout << num << endl;
}
```

- whileループも使えます。

```cpp
int i = 0;
while (i < 5) {
    cout << ++i << endl;
}
```

- do-whileループも使えます。

```cpp
int i = 0;
do {
    cout << ++i << endl;
} while (i < 5);
```

- forループも使えます。

```cpp
for (int i=1; i<=5; i++) {
    cout << i << endl;
}
```

[⬆︎目次へ戻る](#目次)

## 配列

- 1つの変数名で複数の値を保持できます。

```cpp
int arr[3] = {10, 20, 30};
```

- 下記コードで要素数を取得できます。

```cpp
int n = sizeof(arr) / sizeof(arr[0]);
```

[⬆︎目次へ戻る](#目次)

## 多次元配列

- 配列の多次元版です。

```cpp
int arr[3][2] = {{10, 20}, {30, 40}, {50, 60}};
```

- 下記コードで行数や列数、要素数を取得できます。

```cpp
int rows = sizeof(arr) / sizeof(arr[0]);
int cols = sizeof(arr[0]) / sizeof(arr[0][0]);
int elms = sizeof(arr) / sizeof(arr[0][0]);
```

[⬆︎目次へ戻る](#目次)

## 動的配列

- 動的な配列を定義することができます。（C++ではvectorの使用が一般的です）

```cpp
int n = 2;
int* arr = new int[n] {10, 20};
cout << arr[0] << " " << arr[1] << '\n';
delete[] arr;

n = 3;
arr = new int[n] {10, 20, 30};
cout << arr[0] << " " << arr[1] << " " << arr[2] << '\n';
delete[] arr;
```

[⬆︎目次へ戻る](#目次)

## 関数

- 関数が使用できます。

```cpp
void Hello(string name) {
    cout << "Hello, " << name << endl;
}

Hello("WORLD"); // Hello, WORLD
```

- デフォルト引数を指定することもできます。

```cpp
void HelloGuest(string name = "GUEST") {
    cout << "Hello, " << name << endl;
}

HelloGuest();   // Hello, GUEST
```

- 関数の引数が異なる場合に備えたオーバーロードが可能です。

```cpp
void Twice(int x)    { cout << x * 2 << endl; }
void Twice(double x) { cout << x * 2 << endl; }

Twice(10);  // 20
Twice(2.2); // 4.4
```

- 関数に配列を渡すことも可能です。

```cpp
void OutputArray(const int* arr) {
    for (int i=0; i<3; i++) {
        cout << arr[i] << endl;
    }
}

int arr[3] = {10, 20, 30};
OutputArray(arr);
```

[⬆︎目次へ戻る](#目次)

## 構造体

- アクセス修飾子のデフォルトが`public`なクラスです。

```cpp
struct Rectangle {
    int height;
    int width;
};
```

[⬆︎目次へ戻る](#目次)

## クラス

- アクセス修飾子のデフォルトが`private`な複合データ型です。

```cpp
class Rectangle {
    int height_;    // データメンバ
    int width_;     // データメンバ
    int Area() { return height_ * width_; } // データ関数
};
```

- 下記コードは**コンストラクタ**、**クラス外でのデータ関数定義**、**constメンバ関数**、**`this`を使用したデータメンバ指定**が含まれた動作するコードです。

```cpp
class Rectangle {
    int height_;
    int width_;
public:
    Rectangle(int height, int width) : height_(height), width_(width) {}
    int Area() const;
};

int Rectangle::Area() const { return this->height_ * this->width_; }
```

- インスタンス生成を行い、使用できます。

```cpp
Rectangle r(10, 20);
cout << r.Area() << endl;   // 200
```

- クラスは継承が可能です。

```cpp
class Rectangle {};
class Square : public Rectangle {}; // Square はRectangle を継承している
```

[⬆︎目次へ戻る](#目次)

## default / delete

- `default`は、暗黙的に定義されるものと同じものを明示的に定義します。

```cpp
class Calc {
public:
    Calc() = default;
};
```

- `delete`は、暗黙定義を明示的に禁止し、コピーを禁止するような場合に活用できます。

```cpp
class A {
public:
    A(const A&) = delete;
    A() = default;
};

A a1;
A a2 = a1;      // コピーコンストラクタはdelete宣言されているためエラー
```

[⬆︎目次へ戻る](#目次)

## ポインタ

- 値そのものではなく、値を指すメモリアドレスを保持する変数です。

```cpp
int age = 21;
int* p_age = &age;
cout << *p_age << endl; // 21
```

- どの変数も参照していないポインタには`nullptr`を使用できます。

```cpp
int* ptr = nullptr;

int age = 22;
ptr = &age;
cout << *ptr << endl;   // 22
```

- 参考: ポインタの動作制御

```cpp
const int* ptr = &x;        // オブジェクトを不変にする
int* const ptr = &x;        // アドレスを不変にする
const int* const ptr = &x;  // 上記２つを適用
```

- 参考: 参照

```cpp
int age = 10;
int& p = age;       // p は age を参照する
cout << p << endl;  // 10
```

[⬆︎目次へ戻る](#目次)

## ポインタと配列

- ポインタを使用して配列を操作することができます。

```cpp
int arr[3] = {10, 20, 30};
int* ptr = arr;
cout << *ptr << endl;       // 10
cout << *(ptr + 1) << endl; // 20
```

[⬆︎目次へ戻る](#目次)

## ポインタと関数

- 下記コードは「ポインタ渡し」の例です。実施する際はnullチェックを仕込むべきです。

```cpp
bool Twice(int* num) {
    if (num == nullptr) return false;
    *num *= 2;
    return true;
}

int main() {
    int x = 32;
    Twice(&x);
    cout << x << endl;  // 64
    Twice(nullptr);     // nullチェックに引っかかる
}
```

- 下記コードは「参照渡し」の例です。

```cpp
void Swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int a = 100;
    int b = 200;
    Swap(a, b);
    cout << a << " " << b << endl;  // 200 100
}
```

[⬆︎目次へ戻る](#目次)

## ポインタとクラス

- ポインタを使用してクラスを操作することができます。

```cpp
Rectangle r;
Rectangle* rp = &r;
(*rp).height_ = 10;
(*rp).width_ = 20;
cout << rp->Area() << endl; // 200
rp->height_ = 30;
cout << rp->Area() << endl; // 600
```

[⬆︎目次へ戻る](#目次)

## スマートポインタ

スマートポインタはメモリを自動で管理するポインタで、`delete`を自分で書く必要がありません。

- `unique_ptr`は、所有者が１つだけのポインタです。

```cpp
#include <memory>

unique_ptr<int> p = make_unique<int>(10);
cout << *p << endl; // 10
```

- `move` で所有権を移動できます。

```cpp
unique_ptr<int> p1 = make_unique<int>(20);
unique_ptr<int> p2 = std::move(p1);
cout << *p2 << endl;    // 20
```

- `shared_ptr` は、複数のポインタで同じオブジェクトを共有します。

```cpp
shared_ptr<int> p1 = make_shared<int>(30);
shared_ptr<int> p2 = p1;
cout << *p1 << " " << *p2 << endl;  // 30 30
```

- 参照数が0になると自動で削除されます。`use_count` で参照数が確認できます。

```cpp
cout << p1.use_count() << endl; // 2
p2.reset();
cout << p1.use_count() << endl; // 1
```

- `weak_ptr` は、`shared_ptr` を参照するが所有権は持たないポインタです。

```cpp
shared_ptr<int> p = make_shared<int>(40);
weak_ptr<int> w = p;

if (auto sp = w.lock()) {
    cout << *sp << endl;    // 40
}
```

[⬆︎目次へ戻る](#目次)

## 静的

- `static`変数が使用できます。

```cpp
void CountUp() {
    static int cnt = 0;
    cnt++;
    cout << cnt << '\n';
}

CountUp();  // 1
CountUp();  // 2
```

- `static`メンバ変数としても扱えます。

```cpp
class Counter {
public:
    static int cnt;
};

int Counter::cnt = 0;
```

- クラスそのものが持つ`static`メンバ関数も使用できます。

```cpp
class Util {
public:
    static int Add(int a, int b) {
        return a + b;
    }
};

int result = Util::Add(3, 4);
cout << result << endl;     // 7
```

[⬆︎目次へ戻る](#目次)

## テンプレート

- テンプレートは、コンパイル時に型ごとのコードを生成します。

```cpp
template <typename T>
T Sum(T a, T b) {
    return a + b;
};

cout << Sum(1, 4) << "\n";      // 5
cout << Sum(1.2, 3.4) << "\n";  // 4.6
```

- クラスでも使用できます。

```cpp
template <typename T>
class Rectangle {
    int height_;
    int width_;
public:
    Rectangle(T h, T w): height_(h), width_(w) {}
    T Area() { return this->height_ * this->width_; }
};

Rectangle<int> r(10, 20);
Rectangle<double> x(1.2, 3.4);
```

[⬆︎目次へ戻る](#目次)

## キャスト

- `static_cast` は型変換を明示的に行い、必要があれば値を変化させます。

```cpp
double pi = 3.14;
int x = static_cast<int>(pi);   // 3
```

- `dynamic_cast` は、実行時型チェックを伴う安全なダウンキャストです。

```cpp
class Base {
public:
    virtual ~Base() {}
};

class Sub : public Base {};

Base* b = new Sub();
Sub* s = dynamic_cast<Sub*>(b);
```

- `const_cast` はconst修飾を変化させます。

```cpp
string name = "John";
const string& ref = name;

string& x = const_cast<string&>(ref);
x = "Paul";
```

- `istringstream` を使用して、文字列から数値に変換できます。

```cpp
#include <sstream>

...
string x = "10";
int n;
istringstream ss;
ss = istringstream(x);
ss >> n;
cout << n << endl;  // 10
```

- 文字から数値に変換できます。

```cpp
char c = '4';
int n = c - '0';
cout << n << endl;  // 4
```

[⬆︎目次へ戻る](#目次)

## 列挙型

- `enum`では各列挙子が整数として扱われ、指定のない場合0から割り振られます。

```cpp
enum Suit {
    Hearts,     // 0
    Diamonds,   // 1
    Clubs = 5,  // 5
    Spades,     // 6
};

Suit s = Suit::Hearts;  // 0
cout << Suit::Clubs;    // 5
```

- 明示的な型変換をしない限り、数値型に代入できません。

```cpp
int x = static_cast<int>(Suit::Hearts);
```

- `enum class` であれば、他の列挙型の列挙子と名前が被っても問題ありません。

```cpp
enum class Vertical {
    Top = 0,
    Center,
    Bottom,
};

enum class Horizontal {
    Left = 5,
    Center,
    Right,
};
```

[⬆︎目次へ戻る](#目次)

## コマンドライン引数

- プログラムの呼び出し時に引数を渡すことができます。

```cpp
int main(int argc, char* argv[]) {
    for (int i = 0; i < argc; ++i) {
        cout << argv[i] << endl;
    }
}
```

[⬆︎目次へ戻る](#目次)

## コンテナ

用途に応じて、様々なコンテナが使用できます。


- [array](/container/array.cpp)
- [tuple](/container/tuple.cpp)
- [pair](/container/pair.cpp)
- [vector](/container/vector.cpp)
- [map / unordered_map](/container/map.cpp)
- [set / unordered_set](/container/set.cpp)

[⬆︎目次へ戻る](#目次)

## イテレータ

- イテレータは、コンテナを共通の方法で操作する仕組みです。

```cpp
vector<int> v = {10, 20, 30};
auto ite = v.begin();
cout << *ite << endl;   // 10
++ite;
cout << *ite << endl;   // 20
```

- `for` で使用する場合、下記のようになります。

```cpp
vector<int> v = {10, 20, 30};
for (auto ite = v.begin(); ite != v.end(); ++ite) {
    cout << *ite << endl;
}
```

- `範囲for` を使用することで省略できます。

```cpp
vector<int> v = {10, 20, 30};
for (auto&& elm: v) {
    cout << elm << endl;
}
```

[⬆︎目次へ戻る](#目次)

## iostream (標準入出力)

- cout - データを出力する
- cerr - エラーメッセージを出力する
- clog - ログメッセージを出力する
- [cin](/iostream/cin.cpp) - ユーザー入力を読み取る（[複数入力](/iostream/cin2.cpp)、[一行入力](/iostream/cin3.cpp)）
- wcout - wcharを使用したcout
- wcerr - wcharを使用したcerr
- wclog - wcharを使用したclog
- wcin - wcharを使用した[cin](/iostream/cin.cpp)

[⬆︎目次へ戻る](#目次)

## fstream (ファイル)

- [filebuf](/fstream/filebuf.cpp) - ファイルの読み書きに使用されるクラス
- [fstream](/fstream/fstream.cpp) - ファイルの読み取りと書き込みに使用されるクラス
- [ifstream](/fstream/ifstream.cpp) - ファイルからの読み取りに使用されるクラス
- [ofstream](/fstream/ofstream.cpp) - ファイルへの書き込みに使用されるクラス（[ファイル追記](/fstream/ofstream2.cpp)）

[⬆︎目次へ戻る](#目次)

## cmath (数学)

- [abs](/cmath/abs.cpp) - 絶対値を返す
- [ceil](/cmath/ceil.cpp) - 最も近い整数に切り上げ
- fabs - 絶対値を返す
- [floor](/cmath/floor.cpp) - 最も近い整数に切り捨て
- fmax - 最大値を返す
- fmin - 最小値を返す
- fmod - 余りを返す
- hypot - 原点(0, 0)からの2dポイント(x, y)の距離を返す
- pow - べき乗を返す
- remainder - 剰余を返す
- [round](/cmath/round.cpp) - 最も近い整数へ丸める
- [trunc](/cmath/trunc.cpp) - 整数部分を返す

[⬆︎目次へ戻る](#目次)

## string (文字列)

- 文字検索
    - begin - 先頭の要素を示すイテレータを返す
    - end - 末尾の要素を示すイテレータを返す
    - [back](/string/back.cpp) - 末尾の文字にアクセスする
    - front - 先頭の文字にアクセスする（[back.cpp](/string/back.cpp)参照）
    - [find](/string/find.cpp) - 文字列の最初の出現位置を返す
    - rfind - 文字列の最後の出現位置を返す（[find.cpp](/string/find.cpp)参照）
    - [at](/string/at.cpp) - 指定インデックスの文字を返す
    - [substr](/string/substr.cpp) - 開始インデックス（と文字数）を指定して文字列の一部を返す
- 文字変換
    - [append](/string/append.cpp) - 文字列の末尾に文字列を追加する
    - [erase](/string/erase.cpp) - 指定インデックス以降の文字を削除する
    - insert - 指定位置に文字列を挿入する
    - pop_back - 文字列の末尾の文字を削除する
    - push_back - 文字列の末尾に文字を追加する
    - [replace](/string/replace.cpp) - n番目から数えてm文字分を特定の文字に置換する
    - [swap](/string/swap.cpp) - ２つの文字列の内容を交換する
- 文字サイズ関連
    - [empty](/string/empty.cpp) - 文字列が空か確認する
    - [resize](/string/resize.cpp) - 文字列のサイズを変更する
    - [length](/string/length.cpp) - 文字列の長さを返す
    - size - [length](/string/length.cpp)と同様

[⬆︎目次へ戻る](#目次)

## cstring (文字列操作)

[about-c string.h](https://github.com/reiminami/about-c?tab=readme-ov-file#stringh-%E6%96%87%E5%AD%97%E5%88%97%E6%93%8D%E4%BD%9C) 参照

[⬆︎目次へ戻る](#目次)

## ctime (時間)

[about-c time.h](https://github.com/reiminami/about-c?tab=readme-ov-file#timeh-%E6%99%82%E9%96%93) 参照

[⬆︎目次へ戻る](#目次)

## vector (ベクター)

- イテレータ
    - begin	- 先頭の要素を示すイテレータを返す
    - end - 末尾の要素を示すイテレータを返す
    - rbegin - beginの逆順
    - rend - endの逆順
- メモリ
    - capacity - Returns the number of elements that a vector's reserved memory is able to store
    - reserve - Reserves memory for a vector
    - shrink_to_fit - Reduces the reserved memory of a vector if necessary to exactly fit the number of elements
- サイズ
    - [empty](/vector/empty.cpp) - 内容が空か確認する
    - max_size - 格納できる要素の最大数を返す
    - [resize](/vector/resize.cpp) - 要素数を変更する
    - [size](/vector/size.cpp) - 要素数を返す
- 要素追加／削除
    - [clear](/vector/clear.cpp) - 内容をクリアする
    - [erase](/vector/erase.cpp) - 要素を削除する
    - [insert](/vector/insert.cpp) - 指定位置に要素を挿入する
    - [pop_back](/vector/pop_back.cpp) - 末尾の要素を削除する
    - [push_back](/vector/push_back.cpp) - 末尾に要素を追加する
    - [assign](/vector/assign.cpp) - ベクターを別のベクターにコピーする
    - [swap](/vector/swap.cpp) - ２つのベクターの内容を交換する
- 参照
    - [at](/vector/at.cpp) - 指定インデックスの要素を返す
    - [back](/vector/back.cpp)	- 末尾の要素を返す
    - front - 先頭の要素を返す（[back.cpp](/vector/back.cpp)参照）
    - [data](/vector/data.cpp) - 要素を指すメモリブロックのポインタを返す

[⬆︎目次へ戻る](#目次)

## algorithm (アルゴリズム)

- [all_of](/algorithm/all_of.cpp) - データ範囲の各要素が条件に一致するか確認する
- [any_of](/algorithm/any_of.cpp) - データ範囲のいずれかが条件に一致するか確認する
- [binary_search](/algorithm/binary_search.cpp) - データ範囲（ソート済み）に効率的な検索を行う
- [copy](/algorithm/copy.cpp) - データ範囲の内容を別のデータ範囲にコピーする
- [count](/algorithm/count.cpp) - データ範囲内での指定値の出現回数を返す
- [count_if](/algorithm/count_if.cpp) - データ範囲内での検索条件に一致する値の出現回数を返す
- [fill](/algorithm/fill.cpp) - 指定値でデータ範囲を埋める
- [find](/algorithm/find.cpp) - データ範囲内で指定された値の最初の出現位置を指すイテレータを返す
- [find_first_of](/algorithm/find_first_of.cpp) - データ範囲内に対して別のデータ範囲の値を随時検索する（存在しない場合、データ範囲の末尾）
- [find_if](/algorithm/find_if.cpp) - 指定条件に一致するデータ範囲内の最初の値を指すイテレータを返す（存在しない場合、データ範囲の末尾）
- find_if_not - find_ifの逆
- [for_each](/algorithm/for_each.cpp) - データ範囲の全ての要素に対して関数を実行する
- [includes](/algorithm/includes.cpp) - データ範囲（ソート済み）を別のデータ範囲の値で検索して、全て見つかるか確認する
- [is_permutation](/algorithm/is_permutation.cpp) - データ範囲の順列が別のデータ範囲に存在するか確認する
- [is_sorted](/algorithm/is_sorted.cpp) - データ範囲が昇順で並べられているか確認する
- [is_sorted_until](/algorithm/is_sorted_until.cpp) - データ範囲内で、昇順になっていない最初の値へのイテレータを返す
- [lower_bound](/algorithm/lower_bound.cpp) - データ範囲（ソート済み）で、指定値より小さい最初の要素へのイテレータを返す
- [max_element](/algorithm/max_element.cpp) - データ範囲内の最大値へのイテレータを返す
- [merge](/algorithm/merge.cpp) - ２つのデータ範囲の値をマージして別のデータ範囲にコピーする
- [min_element](/algorithm/min_element.cpp) - データ範囲内の最小値へのイテレータを返す
- [none_of](/algorithm/none_of.cpp) - データ範囲の各要素に対して、どの要素も条件が一致しないか確認する
- [replace](/algorithm/replace.cpp) - データ範囲内から指定値を別の値に置き換える
- [replace_copy](/algorithm/replace_copy.cpp) - データ範囲から指定値を別の値に置き換えたコピーを作成する
- [replace_copy_if](/algorithm/replace_copy_if.cpp) - データ範囲から、条件に一致した値を別の値に置き換えたコピーを作成する
- [replace_if](/algorithm/replace_if.cpp) - データ範囲から、条件に一致した値を別の値に置き換える
- [reverse](/algorithm/reverse.cpp) - データ範囲の要素の順序を逆にする
- [reverse_copy](/algorithm/reverse_copy.cpp) - データ範囲の要素の順序を逆にしたコピーを作成する
- [search](/algorithm/search.cpp) - データ範囲内で別のデータ範囲で指定された値のシーケンスを検索する
- [sort](/algorithm/sort.cpp) - データ範囲の要素を昇順で並べ替える
- [swap](/algorithm/swap.cpp) - ２つの変数の値を交換する
- [swap_ranges](/algorithm/swap_ranges.cpp) - データ範囲の値を同じサイズの別のデータ範囲の値と交換する
- [upper_bound](/algorithm/upper_bound.cpp) - データ範囲（ソート済み）で、指定値より大きい最初の要素へのイテレータを返す

[⬆︎目次へ戻る](#目次)

## ビット

- `x & y` - xとyの論理積
- `x | y` - xとyの論理和
- `x ^ y` - xとyの排他的論理和
- `~x` - xの1の補数
- `x << 1` - 左シフト
- `x >> 1` - 右シフト

[⬆︎目次へ戻る](#目次)

## 複数ファイルの使用

ファイルを分割して、他のファイルの関数を呼ぶことができます。

- [main.cpp](/multiple_files/main.cpp)
- [sub.cpp](/multiple_files/sub.cpp)

[⬆︎目次へ戻る](#目次)

## ヘッダファイルの使用

ヘッダファイルを使用することで、複数のソースファイル間で共通のコード部分を宣言および参照することができます。

- [main.cpp](/use_header/main.cpp)
- [f.cpp](/use_header/f.cpp)
- [f.hpp](/use_header/f.hpp)

[⬆︎目次へ戻る](#目次)



