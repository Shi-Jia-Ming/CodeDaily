## 最大单词长度乘积

#### 描述

给你一个字符串数组`words`，找出并返回`length(words[i]) * length(words[j])`的最大值，并且这两个单词不含有公共字母。如果不存在这样的两个单词，返回0。

规定
- `2 <= words.length <= 1000`
- `1 <= words[i].length <= 1000`
- `words[i]`仅包含小写字母

#### 示例

```text
输入：words = ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
输出：16
解释：这两个单词为："abcw", "xtfn"
```
