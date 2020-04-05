SELECT movies.title FROM movies JOIN stars, people
WHERE movies.id IN (SELECT movies.id FROM movies JOIN people, stars
                    WHERE 
                        people.name = "Johnny Depp"
                    AND movies.id = stars.movie_id
                    AND people.id = stars.person_id)
AND people.name = "Helena Bonham Carter"
AND movies.id = stars.movie_id
AND people.id = stars.person_id;