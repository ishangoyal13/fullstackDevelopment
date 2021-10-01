import React from 'react'

import MovieController from '../MovieController/MovieController.jsx'
import { useStyles } from './styles'

const MovieCard = ({ movie, type }) => {
  const classes = useStyles()
  return (
    <div className={classes.wrapper}>
      {movie.poster_path ? (
        <img
          src={`https://image.tmdb.org/t/p/w200${movie.poster_path}`}
          alt={`${movie.title} poster`}
          className={classes.poster}
        />
      ) : (
        <div className={classes.fillerPoster}></div>
      )}

      <MovieController movie={movie} type={type} />
    </div>
  )
}

export default MovieCard
