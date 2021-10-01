import { useDispatch, useSelector } from 'react-redux'
import { Grid, Typography, Button, Card } from '@material-ui/core'

import {
  addToWatchListAction,
  addToWatchedAction,
} from '../../redux/actions/WatchlistActions'
import { useStyles } from './styles'

const ResultCard = ({ movie }) => {
  const classes = useStyles()
  const dispatch = useDispatch()

  const { watchlistMovies, watchedMovies } = useSelector(
    (state) => state.watchlist
  )

  let isWatchlisted =
    watchlistMovies && watchlistMovies.find((item) => item.id === movie.id)

  let isWatched =
    watchedMovies && watchedMovies.find((item) => item.id === movie.id)

  const disabledWatchlist = isWatchlisted ? true : isWatched ? true : false
  const disabledWatched = isWatched ? true : false

  const addToWatchList = () => {
    dispatch(addToWatchListAction(movie))
  }

  const addToWatched = () => {
    dispatch(addToWatchedAction(movie))
  }
  return (
    <div className={classes.resultCard}>
      <Card className={classes.card}>
        <Grid container>
          <Grid item xs={12} sm={6}>
            {movie.poster_path ? (
              <img
                src={`https://image.tmdb.org/t/p/w200${movie.poster_path}`}
                alt={`${movie.title} poster`}
                className={classes.poster}
              />
            ) : (
              <div className={classes.fillerPoster}></div>
            )}
          </Grid>
          <Grid item xs={12} sm={6}>
            <Grid container>
              <Grid item xs={12} sm={12}>
                <Typography variant='h5'>{movie.title}</Typography>
              </Grid>
              <Grid item xs={12} sm={12} className={classes.releaseDate}>
                <Typography variant='body1'>
                  {movie.release_date && movie.release_date.substring(0, 4)}
                </Typography>
              </Grid>
              <Grid item sm={12}>
                <Grid container spacing={8} className={classes.buttonWrapper}>
                  <Grid item sm={6}>
                    <Button
                      color='secondary'
                      variant='contained'
                      onClick={addToWatchList}
                      disabled={disabledWatchlist}
                      className={classes.button}
                    >
                      Add to Watchlist
                    </Button>
                  </Grid>
                  <Grid item sm={6}>
                    <Button
                      color='secondary'
                      variant='contained'
                      onClick={addToWatched}
                      disabled={disabledWatched}
                      className={classes.button}
                    >
                      Add to Watched
                    </Button>
                  </Grid>
                </Grid>
              </Grid>
            </Grid>
          </Grid>
        </Grid>
      </Card>
    </div>
  )
}

export default ResultCard
