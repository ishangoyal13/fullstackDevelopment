import { useSelector } from 'react-redux'
import { Typography, Grid } from '@material-ui/core'
import Alert from '@material-ui/lab/Alert'

import MovieCard from '../../components/MovieCard/MovieCard.jsx'
import { useStyles } from './styles'

const Watchlist = () => {
  const classes = useStyles()

  const { watchlistMovies } = useSelector((state) => state.watchlist)

  return (
    <div className={classes.wrapper}>
      <div className={classes.headerWrapper}>
        <Typography variant='h3' color='secondary'>
          My Watchlist
        </Typography>
      </div>
      {watchlistMovies.length > 0 ? (
        <Grid container className={classes.cardWrapper}>
          {watchlistMovies.map((movie) => (
            <Grid item xs={12} md={6} lg={3}>
              <MovieCard movie={movie} type='watchlist' />
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

export default Watchlist
