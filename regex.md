# regular expressions - Regex
## all regex are meta query
match digits from 0-9 `\d`  
charactar `.`  
zero or more `*`  
macth universe `.*`
#### key single char  
`\d` digits  
`\w` A-Z or a-z or 0-9  
`\s` whitespace  
`.` any char whatever  
capital - not that case  
#### quatifies
`*` zero or more  
`+` one or more  
`?` 0 or 1  
- example: color/colours: `clour?s?`  

#### position  
`^` beginning (called hat)  
`$` end  
`\b` word boundary
- example: every first word in each line: `^\w+`
- example: five char words: `\s\w{5}\s` -> `\b\w{4,6}` -> `\b[a-zA-Z]{5}\b` or only capital words `\b[A-Z][a-z]{4}\b`

#### char class
"alternation": `[]`
- `[abc]` means a or b or c
- `[-.]` hear `.` is a dot (called period)
- `-` need to be at first in char class, or `[a-z]` or `[0-5]{4}`
- `[^a]` means not a  
- `*` is greedy, it matchs the one cannot match any more. To make it not greedy, use `*?`

`(|)` (called pipe symbol)
- email: `[\w.]+@\w+\.(net|com|edu)`
- phone number: `\(?\d{3}[-.)]\d{3}[-.]\d{4}`

#### capture groups
when replacement, `$1` means the first the group we captured.  
`()` means capture a group.  
`(0)` is everything.  

#### back reference
`\1` means is the same capture but use in the same regex.
- classic example: double word: `\b(\w+)\s\1\b`
