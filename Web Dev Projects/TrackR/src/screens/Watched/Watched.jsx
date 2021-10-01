import { useSelector } from 'react-redux'
import { Typography, Grid } from '@material-ui/core'
import Alert from '@material-ui/lab/Alert'

import MovieCard from '../../components/MovieCard/MovieCard.jsx'
import { useStyles } from './styles'

const Watched = () => {
  const classes = useStyles()
  const { watchedMovies } = useSelector((state) => state.watchlist)

  return (
    <div className={classes.wrapper}>
      <div className={classes.headerWrapper}>
        <Typography variant='h3' color='secondary'>
          Watched
        </Typography>
      </div>
      {watchedMovies.length > 0 ? (
        <Grid container className={classes.cardWrapper}>
          {watchedMovies.map((movie) => (
            <Grid item xs={12} md={6} lg={3}>
              <MovieCard movie={movie} type='watched' />
            </Grid>
          ))}
        </Grid>
      ) : (
        <div className={classes.alert}>
          <Alert severity='error'>No movies were found, please add some!</Alert>
        </div>
      )}
    </div>
  )
}

export default Watched
