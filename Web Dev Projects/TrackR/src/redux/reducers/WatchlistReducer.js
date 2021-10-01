import {
  ADD_TO_WATCHLIST,
  REMOVE_FROM_WATCHLIST,
  ADD_TO_WATCHED,
  MOVE_TO_WATCHLIST,
  MARKED_AS_WATCHED,
} from '../constants/WatchConstants'

export const watchlistReducer = (
  state = { watchlistMovies: [], watchedMovies: [] },
  action
) => {
  switch (action.type) {
    case ADD_TO_WATCHLIST:
      return {
        ...state,
        watchlistMovies: [action.payload, ...state.watchlistMovies],
      }
    case REMOVE_FROM_WATCHLIST:
      return {
        ...state,
        watchlistMovies: state.watchlistMovies.filter(
          (movie) => movie.id !== action.payload
        ),
      }
    case ADD_TO_WATCHED:
      return {
        ...state,
        watchlistMovies: state.watchlistMovies.filter(
          (movies) => movies.id !== action.payload.id
        ),
        watchedMovies: [action.payload, ...(state.watchedMovies || [])],
      }
    case MOVE_TO_WATCHLIST:
      return {
        ...state,
        watchedMovies: state.watchedMovies.filter(
          (movies) => movies.id !== action.payload.id
        ),
        watchlistMovies: [action.payload, ...(state.watchlistMovies || [])],
      }
    case MARKED_AS_WATCHED:
      return {
        ...state,
        watchedMovies: state.watchedMovies.filter(
          (movie) => movie.id !== action.payload
        ),
      }
    default:
      return state
  }
}
