import { useState } from 'react'
import { useDispatch } from 'react-redux'
import { IconButton } from '@material-ui/core'
import VisibilityIcon from '@material-ui/icons/Visibility'
import VisibilityOffIcon from '@material-ui/icons/VisibilityOff'
import CancelIcon from '@material-ui/icons/Cancel'

import {
  removeFromWatchListAction,
  addToWatchedAction,
  moveToWatchlistAction,
  markedAsWatchedAction,
} from '../../redux/actions/WatchlistActions'
import { useStyles } from './styles'

const MovieController = ({ movie, type }) => {
  const classes = useStyles()
  const dispatch = useDispatch()
  const [show, setShow] = useState(false)

  return (
    <div
      className={classes.wrapper}
      onMouseEnter={() => setShow((prev) => !prev)}
      onMouseLeave={() => setShow((prev) => !prev)}
    >
      {type === 'watchlist' && (
        <>
          <IconButton
            color='secondary'
            onClick={() => dispatch(addToWatchedAction(movie))}
          >
            {show && <VisibilityIcon />}
          </IconButton>
          <IconButton
            color='secondary'
            style={{ color: 'red' }}
            onClick={() => dispatch(removeFromWatchListAction(movie.id))}
          >
            {show && <CancelIcon />}
          </IconButton>
        </>
      )}

      {type === 'watched' && (
        <>
          <IconButton
            color='secondary'
            onClick={() => dispatch(markedAsWatchedAction(movie.id))}
          >
            {show && <VisibilityOffIcon />}
          </IconButton>
          <IconButton
            color='secondary'
            style={{ color: 'red' }}
            onClick={() => dispatch(moveToWatchlistAction(movie))}
          >
            {show && <CancelIcon />}
          </IconButton>
        </>
      )}
    </div>
  )
}

export default MovieController
