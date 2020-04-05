SELECT title FROM movies
JOIN ratings on movies.id = ratings.movie_id
JOIN stars on people.id = stars.person_id
JOIN people on stars.person_id = people.id
WHERE movies.id IN 
	(SELECT stars.movie_id WHERE stars.person_id = 
		(SELECT id FROM people WHERE name = 'Chadwick Boseman'))
GROUP BY title
ORDER BY ratings.rating DESC LIMIT 5;