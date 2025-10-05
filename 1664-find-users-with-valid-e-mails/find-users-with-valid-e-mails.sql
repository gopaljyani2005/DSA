SELECT *
FROM Users AS u
WHERE REGEXP_LIKE(u.mail, '^[A-Za-z][A-Za-z0-9_\\.\\-]*@leetcode\\.com$', 'c');
