## About C++

*C++17

## 目次

1. [命名規則](#命名規則)
1. [Hello World](#hello-world)
1. [変数と定数](#変数と定数)
1. [データ型](#データ型)
1. [条件分岐](#条件分岐)
1. [ループ](#ループ)
1. [配列](#配列)
1. [列挙型](#列挙型)
1. [関数](#関数)
1. [構造体/クラス](#構造体クラス)
1. [継承](#継承)
1. [ポインタ](#ポインタ)
1. [スマートポインタ](#スマートポインタ)
1. [標準関数](#標準関数)
1. [キャスト](#キャスト)
1. [テンプレート](#テンプレート)
1. [コマンドライン引数](#コマンドライン引数)
1. [ヘッダファイル](#ヘッダファイル)
1. [アルゴリズム](#アルゴリズム)

## 命名規則

**ファイル名**

- ソースファイル名 - `my_source.cpp`
- ヘッダファイル名 - `my_header.hpp`

**基本**

```cpp
// マクロ
#define NEW_LINE '\n'

// クラス
class MyClass {
    int my_var_;    // メンバ変数
    void my_func(); // メンバ関数
};

// 構造体
struct MyStruct {
    int my_var;     // メンバ変数
    void my_func(); // メンバ関数
};

// 列挙型
enum MyEnum {
    ONE, TWO, THREE,  // 列挙子
};

int main() {
    std::string my_var = "Hello";   // 変数
    const double MY_CONST = 3.14;   // 定数
}
```

**共通**

1. アンダースコアで始まる名前はつけない
    予約後と名前衝突する可能性があるため。
1. 略称をなるべく使わない
    `buf` よりも`buffer` の方がわかりやすい。
1. ハンガリアン記法を使わない
    `m_value` とか意味がわからない。
1. 最大40文字まで
    長すぎると見づらい。
1. 機能の目的が明確で、動作や情報に相応しい名前
    初見でわかる方がいい。
1. ヘッダファイルで`using` を使わない
    そのヘッダファイルを読み込んだソースファイルの名前空間が汚染されるから。
1. インクルードガードを使用する
    同じヘッダファイルを複数回インクルードする問題を回避できる。
1. メンバ変数にデフォルト値を割り当てる
    メンバ変数の初期化を忘れると、未定義動作にバグが生じる可能性がある。

[⬆︎目次へ戻る](#目次)

## Hello World

**最低限のコード**

```cpp
#include <iostream>

int main() {
    std::cout << "Hello, World" << std::endl;
}
```

**コンパイル**

```sh
g++ src/sample.cpp -o src/sample
```

**実行**

```sh
./src/sample
```

**ディレクティブ** - includeで標準ライブラリやヘッダファイルをインクルード可能

```cpp
#include <iostream>
#include "sample.h"
```

**using namespace std** - `std::` を省略可能

```cpp
#include <iostream>

using namespace std;

int main() {
    cout << "Hello, World" << endl;
}
```

[⬆︎目次へ戻る](#目次)

## 変数と定数

**変数**

```cpp
string name = "John";
```

**定数**

```cpp
const double PI = 3.14;
```

**constexpr**

```cpp
constexpr double PI = 3.14;

// エラーになる例
double tax = 1.1;
constexpr double TAX = tax; // 既知の値でないためエラー
```

**static変数**

```cpp
static int cnt = 0;
```

[⬆︎目次へ戻る](#目次)

## データ型

**型一覧**

```cpp
string name = "John";       // 文字列
int age = 12;               // 数値
short si = 123;             // 数値 (16bit)
long li = 1234;             // 数値 (64bit)
unsigned int ui = 12345;    // 数値 (正のみ)
float f = 3.14f;            // 浮動小数点型 (32bit, 小数点以下7まで)
double d = 3.14;            // 浮動小数点型 (64bit, 小数点以下15まで)
char c = 'J';               // 文字
bool is_enable = true;      // 真偽値
auto x = "cccx";            // 型推論
```

[⬆︎目次へ戻る](#目次)

## 条件分岐

**if**

```cpp
if (score == 0) {
    cout << 'A' << endl;
} else if (score == 1) {
    cout << 'B' << endl;
} else {
    cout << 'C' << endl;
}
```

**switch**

```cpp
switch (score) {
    case 0:
        cout << 'A' << endl;
        break;
    case 1:
        cout << 'B' << endl;
        break;
    default:
        cout << 'C' << endl;
        break;
}
```

[⬆︎目次へ戻る](#目次)

## ループ

**for**

```cpp
for (int i=0; i<3; i++) {
    cout << i << endl;
}
```

**while**

```cpp
int i = 0;
while (i < 3) {
    cout << i++ << endl;
}
```

**do-while**

```cpp
int j = 0;
do {
    cout << j++ << endl;
} while (j < 3);
```

**範囲for**

```cpp
int nums[] = {10, 20, 30};
for (int num : nums) {
    cout << num << endl;
}
```

[⬆︎目次へ戻る](#目次)

## 配列

**初期化・アクセス**

```cpp
int nums[] = {10, 20, 30, 40};          // 初期化
cout << nums[3] << endl;                // アクセス
cout << sizeof(nums) / sizeof(nums[0]); // 要素数
```

**多次元配列**

```cpp
int arr[3][2] = {{10, 20}, {30, 40}, {50, 60}}; // 初期化
int rows = sizeof(arr) / sizeof(arr[0]);        // 行数
int cols = sizeof(arr[0]) / sizeof(arr[0][0]);  // 列数
int elms = sizeof(arr) / sizeof(arr[0][0]);     // 要素数
```

**動的配列** - (C++の場合はVectorの使用推奨)

```cpp
int n;
int* nums;

n = 2;
nums = new int[n] {10, 20};

n = 3;
nums = new int[n] {10, 20, 30};

delete[] nums;
```

**コンテナ**

- [**vector**](/src/container/vector.cpp) - 動的配列
- [**deque**](/src/container/deque.cpp) - 両端キュー
- [**list**](/src/container/list.cpp) - 単方向リンクリスト
- [**forward_list**](/src/container/forward_list.cpp) - 単方向リスト
- [**array**](/src/container/array.cpp) - 固定長配列
- [**stack**](/src/container/stack.cpp) - LIFO
- [**queue**](/src/container/queue.cpp) - FIFO
- [**priority_queue**](/src/container/priority_queue.cpp) - 優先度付きキュー
- [**set**](/src/container/set.cpp) - 集合
- [**multiset**](/src/container/multiset.cpp) - 集合 (重複許可)
- [**map**](/src/container/map.cpp) - キーと値のペア連想配列
- [**multimap**](/src/container/multimap.cpp) - キーと値のペア連想配列 (重複キー許可)
- **unordered_set** - ハッシュ集合
- **unordered_multiset** - ハッシュ集合 (重複許可)
- **unordered_map** - ハッシュマップ
- **unordered_multimap** - ハッシュマップ (重複キー許可)

[⬆︎目次へ戻る](#目次)

## 列挙型

**enum**

```cpp
enum Direction {
    TOP,        // 0
    BOTTOM,     // 1
    LEFT = 4,   // 4
    RIGHT       // 5
};

int main() {
    Direction dir = Direction::RIGHT;
    cout << dir << endl;
}
```

**キャスト**

```cpp
int right = static_cast<int>(Direction::RIGHT);
if (right == RIGHT) {
    cout << "右" << endl;
}
```

**enum class** - 他の列挙子と同じ名前でもエラーにならない

```cpp
enum class Hand {
    LEFT,
    RIGHT
};

enum class Outfielder {
    LEFT,
    CENTER,
    RIGHT,
};
```

[⬆︎目次へ戻る](#目次)

## 関数

**定義・使用**

```cpp
int sum(int a, int b) {
    return a + b;
}

int main() {
    cout << sum(10, 20) << endl;
}
```

**参照渡し**

```cpp
void plus_one(int& num) {
    num++;
}

int main() {
    int x = 10;
    plus_one(x);
    cout << x << endl;  // 11
}
```

**デフォルト引数**

```cpp
void hello(string name = "WORLD") {
    cout << "Hello, " << name << "!" << endl;
}

int main() {
    hello();        // Hello, WORLD!
    hello("John");  // Hello, John!
}
```

**オーバーロード** - 異なる引数を持つ同じ名前の関数

```cpp
void twice(int x) {}
void twice(double x) {}
```

**関数に配列を渡す**

```cpp
void output_array(const int* nums) {
    for (int i=0; i<3; i++) {
        cout << nums[i] << endl;
    }
}

int main() {
    int nums[5] = {10, 20, 30, 40, 50};
    output_array(nums);
}
```

**static変数を使う**

```cpp
void count_up() {
    static int cnt = 0;
    cnt++;
    cout << cnt << endl;
}
```

[⬆︎目次へ戻る](#目次)

## 構造体/クラス

**クラス** - アクセス修飾子のデフォルトがprivate

```cpp
class Person {
public:
    string name;
};
```

**構造体** - アクセス修飾子のデフォルトがpublic

```cpp
struct Person {
    string name_;
};
```

**インスタンス生成**

```cpp
Person person;
person.name_ = "John";
cout << person.name_ << endl;
```

**基本**

```cpp
struct Rectangle {
    int width_;
    int height_;

    Rectangle(int w, int h): width_(w), height_(h) {}

    int area() const {
        return width_ * height_;
    }
};

int main() {
    Rectangle rect(10, 20);
    cout << rect.area() << endl;
}
```

**クラス外での関数定義**

```cpp
struct Person {
    string name_;
    void display();
};

void Person::display() {
    cout << name_ << endl;
}

int main() {
    Person person;
    person.name_ = "John";
    person.display();
}
```

[⬆︎目次へ戻る](#目次)

## 継承

**継承**

```cpp
struct Square : public Rectangle {
    Square(int side) : Rectangle(side, side) {}
};

int main() {
    Square square(20);
    cout << square.area() << endl;
}
```

**default** - 暗黙的に定義されるものを、明示的に定義する

```cpp
struct Animal {
    Animal() = default;
};
```

**delete** - 暗黙定義を明示的に禁止 (コピー禁止などに使用できる)

```cpp
struct Animal {
    Animal(const Animal&) = delete;
};
```

[⬆︎目次へ戻る](#目次)

## ポインタ

**ポインタ** - 別の変数を操作するための変数

```cpp
int age = 22;
int* ptr = &age;    // ageを指すポインタ
*ptr = 25;          // ptr経由でageを書き換える

age++;
(*ptr)++;

cout << age << endl;    // 27
cout << *ptr << endl;   // 27
cout << &age << endl;   // (アドレス)
cout << ptr << endl;    // (アドレス)
```

**nullptr** - 何も指していないポインタ

```cpp
int* ptr = nullptr;
```

**参照** - 別名

```cpp
int age = 26;
int& my_age = age;  // 別名
my_age = 27;

cout << my_age << endl; // 27
```

**動作制御**

```cpp
int age = 31;
const int* ptr1 = &age;         // オブジェクト不変
int* const ptr2 = &age;         // アドレス不変
const int* const ptr3 = &age;   // オブジェクト＆アドレス不変
```

**配列で使う**

```cpp
int nums[3] = {10, 20, 30};
int* ptr = nums;
cout << *ptr << endl;       // 10
cout << *(ptr + 1) << endl; // 20
```

**ポインタ渡し (nullチェック必須)**

```cpp
bool twice(int* number) {
    if (number == nullptr) return false;
    *number *= 2;
    return true;
}

int main() {
    int x = 64;
    twice(&x);
    cout << x << endl;  // 128
}
```

**参照渡し**

```cpp
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int a = 100;
    int b = 200;
    swap(a, b);
    cout << a << " " << b << endl;  // 200 100
}
```

**クラス操作**

```cpp
Rectangle rect(10, 20);
Rectangle* ptr = &rect;
cout << (*ptr).area() << endl;  // 200
```

[⬆︎目次へ戻る](#目次)

## スマートポインタ

**unique_ptr** - 所有者が1人だけ

```cpp
unique_ptr<int> ptr = make_unique<int>(10);
cout << *ptr << endl;   // 10
```

**move** - 所有者を移動させる

```cpp
unique_ptr<int> ptr1 = make_unique<int>(20);
unique_ptr<int> ptr2 = std::move(ptr1);
cout << *ptr2 << endl;  // 20
```

**shared_ptr** - 複数のポインタで同じオブジェクトを共有する

```cpp
shared_ptr<int> ptr1 = make_shared<int>(30);
shared_ptr<int> ptr2 = ptr1;
cout << *ptr1 << endl;  // 30
cout << *ptr2 << endl;  // 30
```

**use_count** - 参照数を確認 (参照が0になると自動で削除)

```cpp
shared_ptr<int> ptr1 = make_shared<int>(40);
cout << ptr1.use_count() << endl;   // 1
ptr1.reset();
cout << ptr1.use_count() << endl;   // 0 (削除)
```

**weak_ptr** - shared_ptrを参照するが、所有権は持たない

```cpp
shared_ptr<int> ptr1 = make_shared<int>(50);
weak_ptr<int> ptr2 = ptr1;

if (auto sp = ptr2.lock()) {
    cout << *sp << endl;    // 50
}
```

[⬆︎目次へ戻る](#目次)

## 標準関数

**iostream** - 入出力

- [ユーザー入力を読み取る](/src/iostream/input.cpp)
- [複数入力](/src/iostream/multi_input.cpp)

```cpp
cout << "HELLO" << endl;        // 出力
cerr << "ERROR" << endl;        // エラーメッセージ出力
clog << "LOG" << endl;          // ログメッセージ出力
```

**fstream** - ファイル

- [ファイルの書き込み](/src/fstream/file_write.cpp)
- [ファイル追記](/src/fstream/file_appending.cpp)
- [ファイル読み込み](/src/fstream/file_read.cpp)

**cmath** - 数学

```cpp
cout << abs(-4) << endl;                // 絶対値
cout << ceil(1.1) << endl;              // 切り上げ
cout << floor(1.9) << endl;             // 切り捨て
cout << round(4.5) << endl;             // 浮動小数点を丸める
cout << trunc(4.9) << endl;             // 整数部分を返す
cout << fmin(3.1, 3.2) << endl;         // 最小値
cout << fmax(3.1, 3.2) << endl;         // 最大値
cout << fmod(15.0, 2.0) << endl;        // 余り
cout << remainder(15.0, 2.0) << endl;   // 剰余
cout << pow(3.0, 4.0) << endl;          // べき乗
cout << hypot(1.0, 1.0) << endl;        // 原点からの距離
```

**string** - 文字列

```cpp
string txt = "Hello, World";

cout << txt.front() << endl;        // 先頭の文字にアクセス
cout << txt.back() << endl;         // 末尾の文字にアクセス
cout << txt.find("o") << endl;      // 文字列[0]の最初の出現位置
cout << txt.rfind("o") << endl;     // 文字列[0]の最後の出現位置
cout << txt.at(1) << endl;          // 位置[0]の文字
cout << txt.substr(3) << endl;      // 位置[0]から末尾までの文字列
cout << txt.substr(3, 6) << endl;   // 位置[0]から[1]文字目までの文字列
txt.append(" HELLO");               // 文字列[0]を末尾に追加
txt.erase(13);                      // 位置[0]以降の文字の削除
txt.replace(2, 4, "ABCD");          // 位置[0]から文字数[1]分を文字列[2]に置換
txt.insert(4, "cc");                // 位置[0]に文字列[1]を挿入
cout << txt.empty() << endl;        // 文字列が空か？
cout << txt.length() << endl;       // 文字列の長さ
txt.resize(13);                     // 文字列のサイズを変更

// 2つの文字列を交換
string s = "sample";
txt.swap(s);
```

**algorithm** - アルゴリズム

- [イテレータ](/src/algorithm/iterator.cpp)
- [置換](/src/algorithm/replace.cpp)
- [交換](/src/algorithm/swap.cpp)
- [判定](/src/algorithm/judge.cpp)
- [検索](/src/algorithm/search.cpp)
- [ソート](/src/algorithm/sort.cpp)
- [その他](/src/algorithm/misc.cpp)

[⬆︎目次へ戻る](#目次)

## キャスト

**static_cast** - 型変換を明示的に行い、必要があれば値を変更

```cpp
double pi = 3.14;
int x = static_cast<int>(pi);
cout << x << endl;  // 3
```

**dynamic_cast** - 実行時型チェックを伴う安全なダウンキャスト

```cpp
struct Dad {
    virtual ~Dad() {}
};

struct Kid : public Dad {
};

int main() {
    Dad* bro1 = new Kid();
    Kid* bro2 = dynamic_cast<Kid*>(bro1);
}
```

**const_cast** - const修飾を変更

```cpp
string name = "John";
const string& ref_name = name;
string x = const_cast<string&>(ref_name);
x = "Paul";
```

**istringstream** - 文字列から数値に変換

```cpp
#include <iostream>
#include <sstream>
using namespace std;

int main() {
    string num = "10";
    int n;
    istringstream ss;
    ss = istringstream(num);
    ss >> n;    // n = 10
}
```

**charから数値に変換**

```cpp
char c = '4';
int n = c - '0';    // n = 4
```

[⬆︎目次へ戻る](#目次)

## テンプレート

**テンプレート** - コンパイル時に型ごとのコードを生成

```cpp
template <typename T>
T sum(T a, T b) {
    return a + b;
}

int main() {
    cout << sum(10, 20) << endl;        // 30
    cout << sum(15.8, 21.7) << endl;    // 37.5
}
```

**クラスで使う**

```cpp
template <typename T>
struct Calc {
    T width_;
    T height_;
    Calc(T w, T h): width_(w), height_(h) {}
    T area() {
        return width_ * height_;
    }
};

int main() {
    Calc<int> calc1(10, 20);
    cout << calc1.area() << endl;   // 200

    Calc<double> calc2(10.5, 21.6);
    cout << calc2.area() << endl;   // 226.8
}
```

[⬆︎目次へ戻る](#目次)

## コマンドライン引数

**コード**

```cpp
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    for (int i=0; i<argc; ++i) {
        cout << argv[i] << endl;
    }
}
```

**引数なしで実行**

```sh
$ ./src/sample
./src/sample
```

**引数ありで実行**

```sh
$ ./src/sample 10 20 30
./src/sample
10
20
30
```

[⬆︎目次へ戻る](#目次)

## ヘッダファイル

- [sub.hpp](/src/sub.hpp)
- [sub.cpp](/src/sub.cpp)
- [call_sub.cpp](/src/call_sub.cpp)

[⬆︎目次へ戻る](#目次)
