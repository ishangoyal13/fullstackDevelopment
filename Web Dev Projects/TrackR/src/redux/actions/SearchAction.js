import {
  SEARCH_MOVIES_LOADING,
  SEARCH_MOVIES_SUCCESS,
  SEARCH_MOVIES_FAILURE,
} from '../constants/SearchConstants'

import axios from 'axios'

export const searchAction = (searchTerm) => async (dispatch) => {
  try {
    dispatch({ type: SEARCH_MOVIES_LOADING })

    const { data } = await axios.get(
      `https://api.themoviedb.org/3/search/movie?api_key=${process.env.REACT_APP_TMDB_API_KEY}&language=en-US&page=1&include_adult=false&query=${searchTerm}`
    )

    dispatch({ type: SEARCH_MOVIES_SUCCESS, payload: data })
  } catch (error) {
    dispatch({ type: SEARCH_MOVIES_FAILURE, payload: error })
  }
}
