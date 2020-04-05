SELECT name FROM people
JOIN stars on people.id = stars.person_id
JOIN movies on stars.movie_id = movies.id
WHERE movies.year = 2004
GROUP BY stars.person_id
ORDER BY people.birth;
