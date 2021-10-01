import {
  SEARCH_MOVIES_LOADING,
  SEARCH_MOVIES_SUCCESS,
  SEARCH_MOVIES_FAILURE,
} from '../constants/SearchConstants'

export const searchReducer = (state = { movies: [] }, action) => {
  switch (action.type) {
    case SEARCH_MOVIES_LOADING:
      return { loading: true }
    case SEARCH_MOVIES_SUCCESS:
      return { loading: false, movies: action.payload }
    case SEARCH_MOVIES_FAILURE:
      return { loading: false, error: action.payload }
    default:
      return state
  }
}
