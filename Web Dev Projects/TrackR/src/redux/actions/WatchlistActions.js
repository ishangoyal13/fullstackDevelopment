import {
  ADD_TO_WATCHLIST,
  REMOVE_FROM_WATCHLIST,
  ADD_TO_WATCHED,
  MOVE_TO_WATCHLIST,
  MARKED_AS_WATCHED,
} from '../constants/WatchConstants'

export const addToWatchListAction = (movie) => async (dispatch, getState) => {
  dispatch({ type: ADD_TO_WATCHLIST, payload: movie })

  localStorage.setItem(
    'watchlist',
    JSON.stringify(getState().watchlist.watchlistMovies)
  )
}

export const removeFromWatchListAction = (id) => async (dispatch, getState) => {
  dispatch({ type: REMOVE_FROM_WATCHLIST, payload: id })

  localStorage.setItem(
    'watchlist',
    JSON.stringify(getState().watchlist.watchlistMovies)
  )
}

export const addToWatchedAction = (movie) => async (dispatch, getState) => {
  dispatch({ type: ADD_TO_WATCHED, payload: movie })

  localStorage.setItem(
    'watchlist',
    JSON.stringify(getState().watchlist.watchlistMovies)
  )

  localStorage.setItem(
    'watched',
    JSON.stringify(getState().watchlist.watchedMovies)
  )
}

export const moveToWatchlistAction = (movie) => async (dispatch, getState) => {
  dispatch({ type: MOVE_TO_WATCHLIST, payload: movie })

  localStorage.setItem(
    'watchlist',
    JSON.stringify(getState().watchlist.watchlistMovies)
  )

  localStorage.setItem(
    'watched',
    JSON.stringify(getState().watchlist.watchedMovies)
  )
}

export const markedAsWatchedAction = (id) => async (dispatch, getState) => {
  dispatch({ type: MARKED_AS_WATCHED, payload: id })

  localStorage.setItem(
    'watched',
    JSON.stringify(getState().watchlist.watchedMovies)
  )
}
