SELECT name FROM people
JOIN directors on directors.person_id = people.id
JOIN movies on directors.movie_id = movies.id
JOIN ratings on movies.id = ratings.movie_id
WHERE rating >= 9.0
GROUP BY name;